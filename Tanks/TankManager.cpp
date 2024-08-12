#include "TankManager.h"

void TankManager::OnUpdate(float deltaTime)
{

	// SCALE

	float MODIFIER = 1.1;
	MathClasses::Vector3 in(MODIFIER, MODIFIER, 1);

	MODIFIER = 0.9f;
	MathClasses::Vector3 out(MODIFIER, MODIFIER, 1);

	if (GetMouseWheelMove() > 0.0f)
	{
		Scale(in);
	}
	else if (GetMouseWheelMove() < 0.0f)
	{
		Scale(out);
	}

	// COLLISIONS

	size_t i = 0;

	while (i < Children.size())
	{
		size_t j = 0;
		size_t curr_size = Children.size();

		while (j < Children.size() && i < Children.size())
		{
				if (Children[i]->CheckCollision(Children[j]))
				{
					if (curr_size != Children.size()) // if the size of the vector has changed
					{
						j = 0; // restart sub index, as a new obj has taken the old ones place
						curr_size = Children.size(); 
					}
				}

			j++;
		}

		i++;
	}

	// Check Boundary

	// * LocalScale.x is the scale of the object

	float rightBound = (xbound / 2) / LocalScale.x;

	float leftBound = -(xbound / 2) / LocalScale.x;

	float topBound = (ybound / 2) / LocalScale.y;

	float bottomBound = -(ybound / 2) / LocalScale.y;

	GameObject Boundary;
	Boundary.AddTag("ImmovableObject");

	i = 0;

	while (i < Children.size())
	{
		size_t curr_size = Children.size();

		MathClasses::Vector3 pos = Children[i]->GetLocalPosition();
		float xpos = pos.x;
		float ypos = pos.y;

		if (xpos > rightBound || xpos < leftBound || ypos > topBound || ypos < bottomBound)
		{
			Children[i]->OnCollision(&Boundary); // if the object is out of bounds, call the collision function on immovable object. only bullet gets destroyed
			if (curr_size == Children.size()) // only move forward in vector if it wasn't shuffled forward
			{
				i++;
			}
		}
		else
		{
			i++;
		}
		
	}


}

