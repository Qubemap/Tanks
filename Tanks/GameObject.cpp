#include "GameObject.h"

#include <algorithm>
#include <cmath>
#include "raylib-cpp.hpp"

//
// CONSTRUCTORS
//

GameObject::GameObject()
{
	Parent = nullptr;

	LocalPosition = MathClasses::Vector3(0, 0, 1);
	LocalRotation = 0; // ========================= SHOULD BE 0 (1.5708)
	LocalScale = MathClasses::Vector3(1, 1, 1);
}

//
// GETTERS
//

GameObject* GameObject::GetParent()
{
	return Parent;
}

const GameObject* GameObject::GetParent() const
{
	return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return Children[childIndex];
}

MathClasses::Vector3 GameObject::GetLocalPosition() const
{
	return LocalPosition;
}

MathClasses::Vector3 GameObject::GetWorldPosition() const
{
	MathClasses::Matrix3 worldMat = GetWorldMatrix();
	return MathClasses::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetLocalRotation() const
{
	return LocalRotation;
}

float GameObject::GetWorldRotation() const
{
	MathClasses::Vector3 fwd = GetForward(); //----------------------------------------------------------------------------------------------
	return atan2(fwd.x , fwd.y);
}

MathClasses::Vector3 GameObject::GetLocalScale() const
{
	return LocalScale;
}

MathClasses::Vector3 GameObject::GetWorldScale() const
{
	MathClasses::Matrix3 myTransform = GetWorldMatrix();

	return MathClasses::Vector3(MathClasses::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(), MathClasses::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(), 1.0f);
}

MathClasses::Vector3 GameObject::GetForward() const
{
	auto mat = GetWorldMatrix();
	return MathClasses::Vector3(mat[0], mat[1], mat[2]);
}

MathClasses::Matrix3 GameObject::GetLocalMatrix() const
{
	return MathClasses::Matrix3::MakeTranslation(LocalPosition) * MathClasses::Matrix3::MakeRotateZ(LocalRotation) * MathClasses::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

MathClasses::Matrix3 GameObject::GetWorldMatrix() const
{
	if (Parent == nullptr)
	{
		return GetLocalMatrix();
	}
	else
	{
		return Parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

//
// SETTERS
//

void GameObject::SetParent(GameObject* newParent)
{
	// remove from existing parent (if any)
	if (Parent != nullptr)
	{
		auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);
		{
			Parent->Children.erase(findIt);
			Parent = nullptr;
		}
	}

	// add to new parent (if any)
	if (newParent != nullptr)
	{
		Parent = newParent;
		Parent->Children.push_back(this);
	}
}

void GameObject::SetLocalPosition(MathClasses::Vector3 newPosition)
{
	LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
	LocalPosition = MathClasses::Vector3(newX, newY, LocalPosition.z);
}

void GameObject::SetLocalRotation(float newRotation)
{
	LocalRotation = newRotation;
}

void GameObject::SetLocalScale(MathClasses::Vector3 newScale)
{
	LocalScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
	LocalScale = MathClasses::Vector3(newX, newY, LocalScale.z);
}

//
// TRANSFORMATIONS
//

void GameObject::Translate(float x, float y)
{
	LocalPosition += MathClasses::Vector3(x, y, 0);
}

void GameObject::Translate(MathClasses::Vector3 translation)
{
	LocalPosition += translation;
}

void GameObject::Rotate(float radians)
{
	LocalRotation += radians;
}

void GameObject::Scale(float x, float y)
{
	LocalScale *= MathClasses::Vector3(x, y, 1);
}

void GameObject::Scale(MathClasses::Vector3 scaling)
{
	LocalScale *= scaling;
}

//
// FUNCTIONS
//

void GameObject::OnUpdate(float deltaTime)
{

}

void GameObject::OnDraw()
{

}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);

	// TODO: iterate through children and call update on them

}

void GameObject::Draw()
{
	OnDraw();

	// TODO: iterate through children and call Draw on them

}






