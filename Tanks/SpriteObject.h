#pragma once

//#include "raylib-cpp.hpp"
#include "raylib-cpp.hpp"

#include "Colour.h"
#include "GameObject.h"
#include "Circle.h"

class SpriteObject : public GameObject
{
public:

	raylib::Texture2D* Sprite;
	MathClasses::Vector3 Origin;

	MathClasses::Colour Tint;

	SpriteObject();

protected:

	virtual void OnUpdate(float deltaTime) override;

	void OnDraw() override;
};