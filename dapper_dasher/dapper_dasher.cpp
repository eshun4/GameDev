#include "raylib.h"

/*
Create the basic code for dapper_dasher.cpp
*/

struct AnimData{
	Rectangle rec;
	Vector2 pos;
	int frame;
	float updateTime;
	float runningTime;
};


bool isOnGround(AnimData data, int windowHeight){
	return data.pos.y >= windowHeight - data.rec.height;
}

AnimData updateAnimData(AnimData data, float deltaTime, int maxFrame){
	// update running time
	data.runningTime += deltaTime;
	if(data.runningTime >= data.updateTime){
		data.runningTime = 0.0f;
		data.rec.x = data.frame * data.rec.width;
		data.frame++;
		if(data.frame > maxFrame){
			data.frame = 0;
		}
	}
	return data;
}

int main()
{
	// crete an array of size 2
	int windowDimensions[2];
	// WIDTH
	windowDimensions[0] = 1024;
	//HEIGHT
	windowDimensions[1] = 768;

	// Number of frames in the sprite sheet (change this if your sheet has a different amount)
	const int MAX_FRAMES = 7;
	// Call a function that initializes  window (takes multiple input)
	InitWindow(windowDimensions[0], windowDimensions[1], "Dapper Dasher");
	
	// Texture kofi (Anytime we load a texture, we need to make sure to unload it at the end of the program.)
	Texture2D kofi = LoadTexture("textures/kofi_running_forward.png");



	//  For velocity
	int velocity = 0;

	Texture2D background = LoadTexture("textures/far-buildings.png");  
	float bgX = 0.0f;

	Texture2D midground = LoadTexture("textures/back-buildings.png");
	Texture2D foreground = LoadTexture("textures/foreground.png");
	float mgX = 0.0f;
	float fgX = 0.0f;

	// acceleration due to gravity (pixels/second/second)
	const int gravity = 1200;

	// nebula variables
	Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

	// nebula x velocity (pixels/second)
	const int nebulaVelocity = -200;


	// for air Jump
	bool isInAir = false;
	// jump velocity(pixels/second)
	const int jumpVelocity = -600;

	SetTargetFPS(60);
	// Animation frame counter
	int frame = 0;

	// amount of time before we nimate the animation frame
	const float updateTime = 1.0f / 12.0f; // 12 frames per second
	float runningTime = 0.0f;

	// Anim Data for nebula
	AnimData nebulaData{
		{0.0, 0.0, (float)nebula.width / 8.0f, (float)nebula.height / 8.0f}, // rectangle rec
		 {windowDimensions[0], windowDimensions[1] - nebulaData.rec.height}, // vector2 pos
		 0, // int frame
		 1.0f / 12.0f, // float updateTime
		 0.0f // float runningTime
		};

	// Anim Data for nebula2
	AnimData nebula2Data{
		{0.0, 0.0, (float)nebula.width / 8.0f, (float)nebula.height / 8.0f}, // rectangle rec
		 {windowDimensions[0] + 300, windowDimensions[1] - nebula2Data.rec.height}, // vector2 pos
		 0, // int frame
		 1.0f / 16.0f, // float updateTime
		 0.0f // float runningTime
		};

	const int sizeOfNebulae = 6;
	AnimData nebulae[sizeOfNebulae];

	// Iterate through nebulae
	for (int i=0; i < sizeOfNebulae; i++){
		nebulae[i].rec.x = 0.0f;
		nebulae[i].rec.y = 0.0f;
		nebulae[i].rec.width = (float)nebula.width / 8.0f;
		nebulae[i].rec.height = (float)nebula.height / 8.0f;
		nebulae[i].pos.y = windowDimensions[1] - nebulae[i].rec.height;
		nebulae[i].frame = 0;
		nebulae[i].runningTime = 0.0f;
		nebulae[i].updateTime = 1.0f / 16.0f;
		nebulae[i].pos.x = windowDimensions[0] + i * 300;
		
	}

	float finishLine = nebulae[sizeOfNebulae - 1].pos.x + nebulae[sizeOfNebulae - 1].rec.width;

	AnimData kofiData;
	kofiData.rec.width = (float)kofi.width / (float)MAX_FRAMES;
	kofiData.rec.height = (float)kofi.height;
	kofiData.rec.x = 0;
	kofiData.rec.y = 0;
	kofiData.pos.x = windowDimensions[0] / 2 - kofiData.rec.width / 2;
	kofiData.pos.y = windowDimensions[1] - kofiData.rec.height;
	kofiData.frame = 0;
	kofiData.updateTime = 1.0f / 12.0f;
	kofiData.runningTime = 0.0f;


	bool collision = false;


	while(!WindowShouldClose()){

		// delta time (time since last frame, in seconds)
		const float deltaTime = GetFrameTime();
		
		//  apply gravity
		if (isOnGround(kofiData, windowDimensions[1])){
			// rectangle is on the ground
			velocity = 0;
			isInAir = false;
		}
		else{
			velocity += gravity * deltaTime;
			isInAir = true;
		}
		
		if(IsKeyPressed(KEY_SPACE) && !isInAir){
			velocity += jumpVelocity;
		 }

		// update nebula positions
		for(int i = 0; i < sizeOfNebulae; i++){
			nebulae[i].pos.x += nebulaVelocity * deltaTime;
		}
		// update finish line position
		finishLine += nebulaVelocity * deltaTime;
		 
		

		 //  update kofi position
		 kofiData.pos.y += velocity * deltaTime;

	     // DRAW Everything
	     BeginDrawing();
	     ClearBackground(WHITE);

		// ================= BACKGROUND / MIDGROUND / FOREGROUND =================

		// Make each layer tall enough to fill the new window height
		const float bgScale = (float)windowDimensions[1] / background.height;
		const float mgScale = (float)windowDimensions[1] / midground.height;
		const float fgScale = (float)windowDimensions[1] / foreground.height;

		// Each layer needs its own scaled width
		const float bgWidth = background.width * bgScale;
		const float mgWidth = midground.width * mgScale;
		const float fgWidth = foreground.width * fgScale;

		// Move each layer at a different speed for parallax
		bgX -= 20.0f * deltaTime;
		mgX -= 40.0f * deltaTime;
		fgX -= 80.0f * deltaTime;

		// Smooth wrapping for each layer
		if (bgX <= -bgWidth)
		{
			bgX += bgWidth;
		}

		if (mgX <= -mgWidth)
		{
			mgX += mgWidth;
		}

		if (fgX <= -fgWidth)
		{
			fgX += fgWidth;
		}

		// Draw background
		for (float x = bgX; x < windowDimensions[0]; x += bgWidth)
		{
			Vector2 bgPos = {x, 0.0f};
			DrawTextureEx(background, bgPos, 0.0f, bgScale, WHITE);
		}

		// Draw midground
		for (float x = mgX; x < windowDimensions[0]; x += mgWidth)
		{
			Vector2 mgPos = {x, 0.0f};
			DrawTextureEx(midground, mgPos, 0.0f, mgScale, WHITE);
		}

		// Draw foreground
		for (float x = fgX; x < windowDimensions[0]; x += fgWidth)
		{
			Vector2 fgPos = {x, 0.0f};
			DrawTextureEx(foreground, fgPos, 0.0f, fgScale, WHITE);
		}

		//  update scarfy's animation frame
		if(!isInAir){
			 // update animation frame
			kofiData = updateAnimData(kofiData, deltaTime, MAX_FRAMES - 1);
		 }

		for (int i=0; i < sizeOfNebulae; i++){
		 	//  update nebula animation frame
			nebulae[i] = updateAnimData(nebulae[i], deltaTime, 7);
		}

		
		for (AnimData nebula : nebulae){
			float pad = 50;

			Rectangle nebulaRec{
				nebula.pos.x + pad,
				nebula.pos.y + pad,
				nebula.rec.width - 2 * pad,
				nebula.rec.height - 2 * pad
			};

			Rectangle kofiRec{
				kofiData.pos.x,
				kofiData.pos.y,
				kofiData.rec.width,
				kofiData.rec.height
			};

			if(CheckCollisionRecs(nebulaRec, kofiRec)){
				collision = true;
			}

		}

		if(collision){
		// Lose the game
			DrawText("Game Over!", windowDimensions[0] / 2 - MeasureText("Game Over!", 40) / 2, windowDimensions[1] / 2 - 20, 40, RED);

		}else if(kofiData.pos.x > finishLine){
			// Win the game
			DrawText("You Win!", windowDimensions[0] / 2 - MeasureText("You Win!", 40) / 2, windowDimensions[1] / 2 - 20, 40, GOLD);

		} else{
			// Drw texturerec with for loop
			for (int i = 0; i < sizeOfNebulae; i++){
				// draw nebula (white)
				DrawTextureRec(nebula, nebulae[i].rec, nebulae[i].pos, WHITE);
				// Draw the second nebula
				// DrawTextureRec(nebula, nebulae[i].rec, nebulae[i].pos, RED);
			}

			DrawTextureRec(kofi, kofiData.rec, kofiData.pos, WHITE);
		}
		
		
	     EndDrawing();
	}
	UnloadTexture(kofi);
	UnloadTexture(nebula);
	UnloadTexture(background);
	UnloadTexture(midground);
	UnloadTexture(foreground);
	// Closes the window
	CloseWindow();

	return 0;
}
