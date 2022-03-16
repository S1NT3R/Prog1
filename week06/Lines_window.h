#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window
{
	Lines_window(Point xy, int w, int h, const string &title);

private:
	Open_polyline lines;
	Open_polyline workspace;

	Button next_button;
	Button quit_button;
	Button menu_button;
	Button lines_style_button;

	In_box next_x;
	In_box next_y;

	Out_box message;
	Out_box xy_out;
	
	Menu color_menu;
	Menu styles_menu;

	void change(Color c) { lines.set_color(c); }
	void style_change(Line_style s) {lines.set_style(s);}

	void hide_menu()
	{
		color_menu.hide();
		menu_button.show();
	}
	void hide_style_menu(){
		styles_menu.hide();
		lines_style_button.show();
	}
	void red_pressed()
	{
		change(Color::red);
		hide_menu();
	}
	void blue_pressed()
	{
		change(Color::blue);
		hide_menu();
	}
	void black_pressed()
	{
		change(Color::black);
		hide_menu();
	}
	void dash_pressed()
	{
		style_change(Line_style(Line_style::dash));
		hide_style_menu();
	}
	void solid_pressed(){
		style_change(Line_style(Line_style::solid));
		hide_style_menu();
	}
	void dot_pressed()
	{
		style_change(Line_style(Line_style::dot));
		hide_style_menu();
	}
	void dashdot_pressed()
	{
		style_change(Line_style(Line_style::dashdot));
		hide_style_menu();
	}
	void dashdotdot_pressed()
	{
		style_change(Line_style(Line_style::dashdotdot));
		hide_style_menu();
	}
	void menu_pressed()
	{
		menu_button.hide();
		color_menu.show();
	}
	void linemenu_pressed(){
		lines_style_button.hide();
		styles_menu.show();
	}
	void draw_workspace(){
		workspace.add(Point{0,40});
		workspace.add(Point{x_max() - 150, 40});
		workspace.add(Point{x_max() - 150, y_max()});
		workspace.set_style(Line_style({Line_style::solid, 2}));
	}

	void next();
	void quit();
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	static void cb_smenu(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_solid(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_dashdot(Address, Address);
	static void cb_dashdotdot(Address, Address);

};
