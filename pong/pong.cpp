#include "raylib.h"

/*
This contains code for a Pong Game with raylib: Version 1
- This version 1 contains a basic pong game tht allows the 
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

	float gravity = 0.2f;

	// ball coordinates
	float ball_x = WIDTH / 2;
	float ball_y = HEIGHT / 2;

	// Player tile coordinates
	int player_x = (WIDTH / 2) - 40;
	int player_y = HEIGHT - 20;

	// Player speed
	float player_speed = 0;

	// direction
	float direction_x = 0;
	float direction_y = 5;

	int ball_radius = 15;
	int player_length = 100;
	int player_width = 20;

	SetTargetFPS(60);

	while(!WindowShouldClose()){
		// Update the ball movement
		direction_y += gravity;

		// Move ball
                ball_y += direction_y;
		ball_x += direction_x;

		//circle edges
	        int l_ball_x = ball_x - ball_radius;
       	        int r_ball_x = ball_x + ball_radius;
       	        int u_ball_y = ball_y - ball_radius;
                int b_ball_y = ball_y + ball_radius;

		int l_player_x = player_x;
   	        int r_player_x = player_x + player_length;
		int u_player_y = player_y;
       	        int b_player_y = player_y + player_width;


		bool player_top_touches_ball = 
				(b_ball_y >= u_player_y) &&
				(u_ball_y <= b_player_y) &&
				(r_ball_x >= l_player_x) &&
				(l_ball_x <= r_player_x) &&
				(direction_y > 0);

		bool ball_touches_left = l_ball_x <= 0;
		bool ball_touches_right = r_ball_x >= WIDTH;

		if (ball_touches_right || ball_touches_left){
		   direction_x = -direction_x;
		}

		if (u_ball_y <= 0){
		   direction_y = -direction_y;
		}

		if (player_top_touches_ball){
			direction_y = -direction_y;
			// So ball does not get stuck
			ball_y = u_player_y - ball_radius;
				//Optional: paddle movement affects ball direction
			direction_x = (direction_x) + player_speed * 0.4f;
		}

		player_speed = 0;

		// Move Player Logic Below
		if (IsKeyDown(KEY_D) && player_x < (WIDTH - player_length)){
			player_x += 10;
		    player_speed = 5;
        }
		if (IsKeyDown(KEY_A) && player_x > 0){
			player_x -= 10;
	        player_speed = -5;
		}

		// DRAW Everything
		BeginDrawing();
		ClearBackground(WHITE);
        DrawCircle(ball_x, ball_y, ball_radius, RED);
        DrawRectangle(player_x, player_y, player_length, player_width, BLUE);
		// If the ball passes the bottom of the screen
		bool ball_touches_bottom_screen = b_ball_y >= HEIGHT;

		if (ball_touches_bottom_screen){
		   DrawText("Sia Benku!!", 400, 200, 20, RED);
		}
		EndDrawing();
	}

	return 0;
}
