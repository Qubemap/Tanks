#pragma once

#include "SpriteObject.h"
#include "Projectile.h"

class TankPlayer : public SpriteObject
{
public:

	float moveSpeed = 150.0f;

	float rotSpeed = (1 * DEG2RAD);

	float turretSpeed = (1 * DEG2RAD);

	raylib::Texture2D* bulletSprite;

	int reloadTime = 100;


protected:

	void OnUpdate(float deltaTime) override;

	void Shoot();

};
