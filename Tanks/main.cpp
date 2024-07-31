#include "raylib-cpp.hpp"

#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankManager.h"

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	raylib::Texture2D tankSprite("Resources/tankBody_blue_outline.png");
	raylib::Texture2D turretSprite("Resources/specialBarrel1_outline.png");

	raylib::Texture2D bulletSprite("Resources/bulletDark1_outline.png");

	raylib::Texture2D redFenceSprite("Resources/fenceRed.png");
	raylib::Texture2D yellowFenceSprite("Resources/fenceYellow.png");

	TankManager Master;
	Master.SetLocalPosition(screenWidth / 2, screenHeight / 2);

	TankPlayer Player;
	Player.Sprite = &tankSprite;
	Player.SetParent(&Master);

	SpriteObject Turret;
	Turret.Sprite = &turretSprite;
	Turret.Origin = MathClasses::Vector3(0.25f, 0.5f, 0.5f); //Places rear end of turret at centre of tank
	Turret.SetParent(&Player);

	SpriteObject RedFence;
	RedFence.Sprite = &redFenceSprite;
	RedFence.SetLocalPosition(-100, -100);
	RedFence.SetParent(&Master);

	SpriteObject YellowFence;
	YellowFence.Sprite = &yellowFenceSprite;
	YellowFence.SetLocalPosition(100, 100);
	YellowFence.SetParent(&Master);


	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		float deltaTime = GetFrameTime();

		Master.Update(deltaTime);

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);

			Master.Draw();
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