#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string &title)
    : Window{xy, w, h, title},
      next_button{Point{x_max() - 300, 0}, 150, 40, "Next point",
                  [](Address, Address pw)
                  { reference_to<Lines_window>(pw).next(); }},
      quit_button{Point{x_max() - 150, 0}, 150, 40, "Quit",
                  [](Address, Address pw)
                  { reference_to<Lines_window>(pw).quit(); }},
      next_x{Point{300, 0}, 50, 40, "next x:"},
      next_y{Point{410, 0}, 50, 40, "next y:"},
      message{Point{550, 0}, 350, 40, "Message:"},
      xy_out{Point{100, 0}, 100, 40, "current (x,y):"},
      color_menu{Point{x_max() - 150, 40}, 150, 20, Menu::vertical, "color"},
      menu_button{Point{x_max()- 150, 40}, 150, 20, "Color menu", cb_menu},
      lines_style_button{Point{x_max() - 150, 200}, 150, 20, "Line Style", cb_smenu},
      styles_menu{Point{x_max() - 150, 200}, 150, 20, Menu::vertical, "style"}
{
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "red", cb_red});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue", cb_blue});
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "black", cb_black});
    styles_menu.attach(new Button{Point{0, 0}, 0, 0, "solid", cb_solid});
    styles_menu.attach(new Button{Point{0, 0}, 0, 0, "dash", cb_dash});
    styles_menu.attach(new Button{Point{0, 0}, 0, 0, "dot", cb_dot});
    styles_menu.attach(new Button{Point{0, 0}, 0, 0, "dashdot", cb_dashdot});
    styles_menu.attach(new Button{Point{0, 0}, 0, 0, "dashdotdot", cb_dashdotdot});
    attach(color_menu);
    attach(styles_menu);
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    attach(lines);
    color_menu.hide();
    attach(menu_button);
    draw_workspace();
    attach(workspace);
    attach(message);
    message.put("Ready");
    styles_menu.hide();
    attach(lines_style_button);
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_smenu(Address, Address pw)
{
    reference_to<Lines_window>(pw).linemenu_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_dashdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdot_pressed();
}

void Lines_window::cb_dashdotdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdotdot_pressed();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    message.put("Ready");
    int x = next_x.get_int();
    int y = next_y.get_int() + 40;
    if (x < 0){
        message.put("X can't be negative");
        x = 0;
    }
    if (x > x_max()-150){
        message.put("X is greater then window size");
        x = x_max()-150;
    }
    if (y < 40){
        message.put("Y can't be negative");
        y = 40;
    }
    if (y > y_max()){
        message.put("Y is greater then window size");
        y = y_max();
    }

    lines.add(Point{x, y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

