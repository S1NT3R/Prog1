/*
    g++ Ch16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o Ch16 `fltk-config --ldflags --use-images`
*/
#include "GUI.h"
#include "Lines_window.h"
#include "Graph.h"


int main()
try
{
    using namespace Graph_lib;
    Lines_window win{Point{100, 100}, 1280, 720, "lines"};
    return gui_main();
}

catch (exception &e)
{
    cerr << "exception: " << e.what() << '\n';
    return 1;
}

catch (...)
{
    cerr << "Some exception\n";
    return 2;
}