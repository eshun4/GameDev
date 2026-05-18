#include "raylib.h"

//Numbers with fractional prt are floating-point numbers
// Float has less precision and less memory
// Double has more precision and more memory.
// Boolean -true or false

int main()
{
	// Function body
	int width;
	width = 350;
	// Call a function that initializes  window (takes multiple input)
	InitWindow(width, 200, "Stephen's Window");
	float root_beer{1.99};
	double cheese_burger{5.99};
	bool shouldHaveLunch{true};
	bool equal{4 == 9};
	bool notEqual{4 != 9};

	while(true){
		BeginDrawing();
		ClearBackground(BLUE);
		EndDrawing();
	}

	return 0;
}
