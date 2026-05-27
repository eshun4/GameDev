#include "raylib.h"

/*
This contains code for a Pong Game with raylib: Version 1
- This version 1 contains a basic tetris gme tht allows the 
user to control the tile/board and hit the ball unto the top,
left and right portions of the  screen.
*/

// This line contains the width and height dimensions for the Video Game Window.
const int WIDTH = 800;
const int HEIGHT =  400;

int main()
{
	// Call a function that initializes  window (takes multiple input)
	InitWindow(WIDTH, HEIGHT, "Kofi's PONG V1");

	// ball coordinates
	int ball_x = WIDTH / 2;
	int ball_y = HEIGHT / 2;

	// Player tile coordinates
	int player_x = (WIDTH / 2) - 40;
	int player_y = HEIGHT - 20;

	// direction
	int direction = 5;

	int ball_radius = 15;
	int player_length = 100;
	int player_width = 20;

	//circle edges
	int l_ball_x = ball_x - ball_radius;
	int r_ball_x = ball_x + ball_radius;
	int u_ball_y = ball_y - ball_radius;
	int b_ball_y = ball_y + ball_radius;

	// axe edges
	int l_player_x = player_x;
	int r_player_x = player_x + player_length;
	int u_player_y = player_y;
	int b_player_y = player_y + player_length;

	// colision with axe
	//bool collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;

//	bool player_top_touches_ball =  b_ball_y >= u_player_y;

	SetTargetFPS(60);
	while(!WindowShouldClose()){
		
		// Move ball
                ball_y += direction;

		//circle edges
	        int l_ball_x = ball_x - ball_radius;
       	        int r_ball_x = ball_x + ball_radius;
       	        int u_ball_y = ball_y - ball_radius;
                int b_ball_y = ball_y + ball_radius;

		l_player_x = player_x;
   	        r_player_x = player_x + player_length;

		bool player_top_touches_ball = (b_ball_y >= u_player_y) && 
                                   (r_ball_x >= l_player_x) && 
                                   (l_ball_x <= r_player_x);


                if (ball_y > HEIGHT || b_ball_y > HEIGHT || ball_y < 0 || (player_top_touches_ball && direction > 0)){
                   direction = -direction;
                }



		BeginDrawing();
		ClearBackground(WHITE);
		// if/else statement for collision of axe
		//if (collision_with_axe){
		  // DrawText("Game Over", 400, 200, 20, RED);
		//}
		//else{
		// Update Edges
		//l_circle_x = circle_x - circle_radius;
		//r_circle_x = circle_x + circle_radius;
		//u_circle_y = circle_y - circle_radius;
		//b_circle_y = circle_y + circle_radius;
		//l_axe_x = axe_x;
		//r_axe_x = axe_x + axe_length;
		//u_axe_y = axe_y;
		//b_axe_y = axe_y + axe_length;
		// Update collison with axe
		//collision_with_axe = b_axe_y >= u_circle_y && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;

                // Game Logic Begins
                DrawCircle(ball_x, ball_y, ball_radius, RED);
                DrawRectangle(player_x, player_y, player_length, player_width, BLUE);
		// Move ball
		//ball_y += direction;

                //if (ball_y > HEIGHT || ball_y < 0 || (player_top_touches_ball && direction > 0)){
                  // direction = -direction;
               // }

                // Move Player Logic Below
                if (IsKeyDown(KEY_D) && player_x < (WIDTH - player_length)){
                    player_x += 5;
                }
                else if (IsKeyDown(KEY_A) && player_x > 0){
                   player_x -= 5;
                }

		EndDrawing();
	}

	return 0;
}
