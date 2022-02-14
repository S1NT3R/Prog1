/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{

    using namespace Graph_lib;

    const int xwin{800};  //ablakméret változtatva
    const int ywin{600};

    Simple_window win{Point{300, 100}, xwin, ywin, "My window"};  //kiindulási pozíció megváltoztatva

    Axis xa{Axis::x, Point{400, 300}, 280, 10, "x tengely"};  // tengelyek elmozgatva
    Axis ya{Axis::y, Point{400, 300}, 280, 10, "y tengely"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);

    Function sine{sin, 0, 100, Point{0, 150}, 1000, 50, 50};  //kiindulási pozíció megváltoztatva
    sine.set_color(Color::red);

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::dark_blue);
    poly.set_style(Line_style::dash);
    

    Rectangle r{Point{200, 200}, 100, 50};

    Closed_polyline poly_rect;
    poly_rect.add(Point{80, 50});    //pontok elmozgatva
    poly_rect.add(Point{200, 50});   //az új koordinátarendszer
    poly_rect.add(Point{200, 100});  //érintéséhez
    poly_rect.add(Point{80, 100});

    Text t{Point{300, 500}, "Valami uj kezdete..."};  //szöveg kicserélve, elmozgatva

    Image ii{Point{100, 50}, "badge.jpg"};

    Circle c{Point{100, 500}, 50};      //"bolygó" alakzat elmozgatva
    Ellipse e{Point{100, 500}, 75, 25};
    e.set_color(Color::dark_cyan);      //szín kicserélve
    Mark m{Point{100, 500}, 'x'};
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};
    Image cal{Point{225, 225}, "cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(xa);
    win.wait_for_button();

    win.set_label("My window #2");
    win.attach(ya);
    win.wait_for_button();

    win.set_label("My window #3");
    win.attach(sine);
    win.wait_for_button();

    win.set_label("My window #4");
    win.attach(poly);
    win.wait_for_button();

    win.set_label("My window #5");
    win.attach(r);
    win.wait_for_button();

    win.set_label("My window #6");
    win.attach(poly_rect);
    win.wait_for_button();

    win.set_label("My window #6.1");
    poly_rect.add(Point{50, 75});
    win.attach(poly_rect);
    win.wait_for_button();

    win.set_label("My window #7");
    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    poly.set_fill_color(Color::cyan); //háromszög belseje kiszínezve
    win.wait_for_button();

    win.set_label("My window #8");
    win.attach(t);
    win.wait_for_button();

    win.set_label("My window #9");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.wait_for_button();

    win.set_label("My window #10");
    win.attach(ii);
    win.wait_for_button();

    win.set_label("My window #10.1");
    ii.move(100, 200);
    win.wait_for_button();

    win.set_label("My window #11");
    win.attach(c);
    win.attach(m);
    win.attach(e);
    win.attach(sizes);
    win.attach(cal);
    win.wait_for_button();

    return 0;
}