#include "raylib.h"

/*
Create the basic code for dapper_dasher.cpp
*/


int main()
{
	//Constants for the Window Dimensions
	const int WIDTH = 800;
	const int HEIGHT = 400;

	// Call a function that initializes  window (takes multiple input)
	InitWindow(WIDTH, HEIGHT, "Dapper Dasher");
	
	const int width = 50;
	const int height = 50;

	int posY = HEIGHT - height;
	//  For velocity
	int velocity = 0;
	// acceleration due to gravity (pixels/frame/frame)
	const int gravity = 1;

	// for air Jump
	bool isInAir;
	// jump velocity
	const int jumpVelocity = -22;

	SetTargetFPS(60);

	while(!WindowShouldClose()){
	     // DRAW Everything
	     BeginDrawing();
	     ClearBackground(WHITE);


		//  apply gravity
		if (posY >= HEIGHT - height){
			// rectangle is on the ground
			velocity = 0;
			isInAir = false;
		}
		else{
			velocity += gravity;
			isInAir = true;
		}
		
		if(IsKeyPressed(KEY_SPACE) && !isInAir){
			velocity += jumpVelocity;
		 }
		 

		 //  update the position
		 posY += velocity;
		 
		 DrawRectangle(WIDTH/2, posY, width, height, BLUE);
	     EndDrawing();
	}
	// Closes the window
	CloseWindow();

	return 0;
}
