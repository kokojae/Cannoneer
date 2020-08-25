#include "DXUT.h"
#include "ObjectManager.h"
#include "Cannoneer.h"

std::list<GameObject*> ObjectManager::objectList = std::list<GameObject*>();

void ObjectManager::Update()
{
	std::list<GameObject*>::iterator it = objectList.begin();

	while (it != objectList.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		if (inst->destroy)
		{
			inst->Release();
			objectList.erase(it++);
			delete inst;
			continue;
		}

		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (GameObject* inst : objectList)
	{
		if (inst->destroy)
			continue;
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (GameObject* inst : objectList)
	{
		if (inst->destroy)
			continue;
		inst->Render();
	}
}

void ObjectManager::Release()
{
	std::list<GameObject*>::iterator it = objectList.begin();

	while (it != objectList.end())
	{
		GameObject* inst = it._Ptr->_Myval;

		inst->Release();
		objectList.erase(it++);
		delete inst;
	}
}

void ObjectManager::Clear()
{
	for (GameObject* inst : objectList)
	{
		inst->destroy = true;
	}
}

GameObject* ObjectManager::ColliderCheck(RECT* objRect, int layer)
{
	for (GameObject* inst : objectList)
	{
		if (!(inst->collider.layer & layer))
			continue;
		if (!inst->collider.enable)
			continue;
		if (inst->destroy)
			continue;

		if (IntersectRect(&RECT(), inst->GetRect(), objRect))
			return inst;
	}
	return nullptr;
}

bool SortZ(const GameObject* a, const GameObject* b)
{
	return a->z < b->z;
}
