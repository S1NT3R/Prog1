/*
	g++ Ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <experimental/random>


int main()
{
	using namespace Graph_lib;

	constexpr int xmax = 1000;
	constexpr int ymax = 800;

	constexpr int x_orig = xmax / 2;
	constexpr int y_orig = ymax / 2;

	Simple_window win{Point{100, 100}, xmax, ymax, "Grid"};

	Point origo{x_orig, y_orig};

	constexpr int grid_end = 801;
	constexpr int grid_size = 100;
	Lines grid;
	for (int x = grid_size; x < grid_end; x += grid_size)
		grid.add(Point{x, 0}, Point{x, grid_end});
	for (int y = grid_size; y < grid_end; y += grid_size)
		grid.add(Point{0, y}, Point{grid_end, y});

	Vector_ref<Rectangle> squares;
	for (int i = 0; i < 8; ++i)
	{
		squares.push_back(new Rectangle(Point{i * grid_size, i * grid_size}, grid_size, grid_size));
		squares[squares.size() - 1].set_color(Color::invisible);
		squares[squares.size() - 1].set_fill_color(Color::red);
		win.attach(squares[squares.size() - 1]);
	}

	Vector_ref<Image> pics {
		new Image (Point{300, 0}, "pic3.jpg"),
		new Image (Point{100, 300}, "pic4.jpg"),
		new Image (Point{200, 600}, "pic5.jpg")
	};

	for (int i = 0; i < pics.size(); ++i){
		win.attach(pics[i]);
	}
	Image primary {Point(0,0), "pic2.jpg"};
	win.attach(primary);

	win.attach(grid);
	
	int point = std::experimental::randint(2, 64);
	Image jumpscare{Point{200, 200}, "jumpscare.jpg"};
	int counter = 1;
	int move_x = 100;
	int move_y = 0;
	for (int i = 1; i <= 8; ++i){
		for (int j = 1; j <= 8; ++j){
			win.wait_for_button();
			win.detach(jumpscare);
			move_x = 100;
			move_y = 0;
			if (j == 8){
				move_x = -700;
				move_y += 100;
			}
			primary.move(move_x, move_y);
			counter++;
			if (counter == point){
				win.attach(jumpscare);
			}
		}
	}
	
	
}
