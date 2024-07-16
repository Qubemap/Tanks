#pragma once

#include <vector>

#include "Vector3.h"
#include "Matrix3.h"

using::MathClasses::Vector3;
using::MathClasses::Matrix3;

class GameObject
{
protected:

	//
	// DATA
	//

	// Position relative to parent
	Vector3 LocalPosition;

	// rotation relative to parent (in radians)
	float LocalRotation;
	
	// Scale relative to parent
	Vector3 LocalScale;

	// Pointer to parent
	GameObject* Parent;

	// Vector of children
	std::vector<GameObject*> Children;

	//
	// FUNCTIONS
	//

	// Called when obj needs to update
	virtual void OnUpdate(float deltaTime);

	// Called when this specific object needs to draw to the screen
	virtual void OnDraw();

public:

	//
	// CONSTRUCTORS
	//

	// Set default values for its data members
	GameObject();

	//
	// GETTERS
	//

	GameObject* GetParent();

	const GameObject* GetParent() const;

	// Get child at index
	GameObject* GetChild(size_t childIndex);

	// Get a child at index - const-qualified
	const GameObject* GetChild(size_t childIndex) const;

	Vector3 GetLocalPosition() const;

	Vector3 GetWorldPosition() const;

	float GetLocalRotation() const;

	float GetWorldRotation() const;

	Vector3 GetLocalScale() const;

	Vector3 GetWorldScale() const;

	Vector3 GetForward() const;

	Matrix3 GetLocalMatrix() const;

	Matrix3 GetWorldMatrix() const;

	//
	// SETTERS
	//

	// Set a new parent for this object and/or unassign the original
	void SetParent(GameObject* parent);

	void SetLocalPosition(Vector3 newPosition);

	void SetLocalPosition(float newX, float newY);

	void SetLocalRotation(float newRotation);

	void SetLocalScale(Vector3 newScale);

	void SetLocalScale(float newX, float newY);

	//
	// TRANSFORMATIONS
	//

	// Move locally on X and Y axis - Z is untouched
	void Translate(float x, float y);

	// Move locally on X, Y, Z axes
	void Translate(Vector3 translation);

	// Rotate locally by given number of radians
	void Rotate(float radians);

	// Scale locally on X and Y axis - Z is untouched
	void Scale(float x, float y);

	// Scale locally on x, y. Z axes
	void Scale(Vector3 scalar);

	//
	// FUNCTIONS
	//

	// Updates this object and all of its children
	void Update(float deltaTime);

	// Draws this object and all of its children
	void Draw();

};