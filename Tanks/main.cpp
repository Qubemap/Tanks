#include "raylib-cpp.hpp"

#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankManager.h"
#include "Projectile.h"

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

	
	raylib::Texture2D trapSprite("Resources/barricadeWood.png");

	TankManager Master;
	Master.SetLocalPosition(screenWidth / 2, screenHeight / 2);
	Master.xbound = 800.0f;
	Master.ybound = 450.0f;

	SpriteObject TankTrap;
	TankTrap.Sprite = &trapSprite;
	TankTrap.SetParent(&Master);
	TankTrap.SetLocalPosition(-400, 100);
	TankTrap.AddTag("ImmovableObject");

	TankPlayer Player;
	Player.Sprite = &tankSprite;
	Player.SetParent(&Master);
	Player.bulletSprite = &bulletSprite;

	SpriteObject Turret;
	Turret.Sprite = &turretSprite;
	Turret.Origin = MathClasses::Vector3(0.25f, 0.5f, 0.5f); //Places rear end of turret at centre of tank
	Turret.SetParent(&Player);

	


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