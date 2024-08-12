#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = MathClasses::Vector3(0.5f, 0.5f, 0.5f);
	Tint = MathClasses::Colour(255, 255, 255, 255);
}

void SpriteObject::OnUpdate(float deltaTime)
{
	if (Sprite != nullptr)
	{
		MathClasses::Vector3 pos = GetWorldPosition();
		MathClasses::Vector3 scale = GetWorldScale();
		MathClasses::Vector2 center(pos.x, pos.y);
		float radius = (((float)Sprite->width * scale.x) / 2);
		hitbox.center = center;
		hitbox.radius = radius;
	}
}

void SpriteObject::OnDraw()
{
	// extract transform data position
	MathClasses::Vector3 pos = GetWorldPosition();
	float rot = GetWorldRotation() * RAD2DEG;
	MathClasses::Vector3 scale = GetWorldScale();

	// draw the sprite
	Sprite->Draw(
		raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height), 
		raylib::Rectangle(pos.x, pos.y, Sprite->width * scale.x, Sprite->height * scale.y), 
		raylib::Vector2(Sprite->width * Origin.x * scale.x, Sprite->height * Origin.y * scale.y), 
		rot, 
		raylib::Color(Tint.GetRed(), Tint.GetGreen(), Tint.GetGreen(), Tint.GetAlpha()));

}

