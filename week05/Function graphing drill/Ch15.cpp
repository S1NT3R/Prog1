/*
    g++ Ch15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch15 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one (double) {return 1;}

double slope (double x) {return x/2;}

double square (double x) {return x*x;}

double sloping_cos (double x) {return cos(x) + slope(x);}

int main(){

    constexpr int xmax = 600;
    constexpr int ymax = 600;

    constexpr int x_orig = xmax / 2;
    constexpr int y_orig = ymax / 2;

    constexpr int length = 400;
    constexpr int scale = 20;

    const vector<int> range {-10, 11};

    const Point origo {x_orig, y_orig};

    Simple_window win {Point{600, 200}, xmax, ymax, "Function Graphs"};

    Axis x {Axis::x, Point{x_orig -200, y_orig}, length, 20, "1==20 pixels" };
    x.set_color(Color::red);
    Axis y {Axis::y, Point{x_orig, y_orig + 200}, length, 20, "1==20 pixels"};
    y.set_color(Color::red);

    Function fct_one (one, range[0], range[1], origo, length, scale, scale);
    Function fct_slope (slope, range[0], range[1], origo, length, scale, scale);
    Function fct_square(square, range[0], range[1], origo, length, scale, scale);
    Function fct_cos(cos, range[0], range[1], origo, length, scale, scale);
    Function fct_sloping_cos(sloping_cos, range[0], range[1], origo, length, scale, scale);
    fct_cos.set_color(Color::blue);

    Text t{Point{100, 420}, "x/2"};

    win.attach(x);
    win.attach(y);
    win.attach(fct_one);
    win.attach(fct_slope);
    win.attach(fct_square);
    win.attach(fct_cos);
    win.attach(fct_sloping_cos);
    win.attach(t);

    win.wait_for_button();
}