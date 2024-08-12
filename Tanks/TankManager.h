#pragma once

#include "GameObject.h"
#include "raylib-cpp.hpp"

class TankManager : public GameObject
{
public:

	float xbound;

	float ybound;

protected:

	void OnUpdate(float deltaTime) override;
};