#include "raylib-cpp.hpp"

#include "SpriteObject.h"
#include "TankPlayer.h"

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	raylib::Texture2D tankSprite("Resources/tankBody_green.png");
	raylib::Texture2D turretSprite("Resources/tankDark_Barrel1.png");

	TankPlayer Player;
	Player.Sprite = &tankSprite;
	Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

	SpriteObject Turret;
	Turret.Sprite = &turretSprite;
	Turret.SetParent(&Player);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		Player.Update(deltaTime);

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);

			Player.Draw();
		}

		//ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------


	//meow
	return 0;
}