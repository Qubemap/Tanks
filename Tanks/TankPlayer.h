#pragma once

#include "SpriteObject.h"
#include "Projectile.h"

class TankPlayer : public SpriteObject
{
public:

	float scaleMod = 0.0f;

	float moveSpeed = 150.0f;

	float rotSpeed = (1 * DEG2RAD);

	float turretSpeed = (1 * DEG2RAD);

	raylib::Texture2D* bulletSprite;

	int reloadTime = 100;

	float delta;

protected:

	void OnUpdate(float deltaTime) override;

	void Shoot();

};
