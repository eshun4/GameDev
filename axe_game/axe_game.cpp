#include "raylib.h"

//Numbers with fractional prt are floating-point numbers
// Float has less precision and less memory
// Double has more precision and more memory.
// Boolean -true or false

// WindowShouldCLose returns True if we have pressed X or escpe key

int main()
{
	//window dimensions
	int width{800};
	int height{450};
	// Call a function that initializes  window (takes multiple input)
	InitWindow(width, height, "Kofi's Window");
	// circle coordinates
	int circle_x{width / 2};
	int circle_y{height / 2};
	// axe coordintes
	int axe_x{400};
	int axe_y{0};

	// direction
	int direction{10};

	float root_beer{1.99};
	double cheese_burger{5.99};
	bool shouldHaveLunch{true};
	bool equal{4 == 9};
	bool notEqual{4 != 9};

	int circle_radius{25};
	int axe_length{50};

	//circle edges
	int l_circle_x{circle_x - circle_radius};
	int r_circle_x{circle_x + circle_radius};
	int u_circle_y{circle_y - circle_radius};
	int b_circle_y{circle_y + circle_radius};

	// axe edges
	int l_axe_x{axe_x};
	int r_axe_x{axe_x + axe_length};
	int u_axe_y{axe_y};
	int b_axe_y{axe_y + axe_length};

	// colision with axe
	bool collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;


	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);
		// if/else statement for collision of axe
		if (collision_with_axe){
		   DrawText("Game Over", 400, 200, 20, RED);
		}
		else{
		// Update Edges
		l_circle_x = circle_x - circle_radius;
		r_circle_x = circle_x + circle_radius;
		u_circle_y = circle_y - circle_radius;
		b_circle_y = circle_y + circle_radius;
		l_axe_x = axe_x;
		r_axe_x = axe_x + axe_length;
		u_axe_y = axe_y;
		b_axe_y = axe_y + axe_length;
		// Update collison with axe
		collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;

                 // Game Logic Begins
                DrawCircle(circle_x, circle_y, circle_radius, BLUE);
                DrawRectangle(axe_x, axe_y, axe_length, axe_length, GREEN);

                // move the axe
                axe_y += direction;
                if (axe_y > height || axe_y < 0){
                   direction = -direction;
                }

                //Game Logic Ends
                if (IsKeyDown(KEY_D) && circle_x < width){
                    circle_x += 10;
                }
                else if (IsKeyDown(KEY_A) && circle_x > 0){
                   circle_x -= 10;
                }
		}
		EndDrawing();
	}

	return 0;
}
