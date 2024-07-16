#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = Vector3(0.5f, 0.5f, 0.5f);
	Tint = MathClasses::Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	// extract transform data position
	Vector3 pos = GetWorldPosition();
	float rot = GetWorldRotation() * RAD2DEG;
	Vector3 scale = GetWorldScale();

	// draw the sprite
	Sprite->Draw(raylib::Rectangle(0, 0, (float)Sprite->width, (float)Sprite->height), raylib::Rectangle(pos.x, pos.y, Sprite->width * scale.Cross, Sprite->height * scale.y), raylib::Vector2(Sprite->width * Origin.x * scale.x, Sprite->height * Origin.y * scale.y), rot, raylib::Color(Tint.rgba));


}