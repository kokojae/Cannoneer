#pragma once
#include <iostream>
#include "TextureInfo.h"
#include "BoxCollider.h"
#include "MouseManager.h"

class GameObject
{
public:
	D3DXVECTOR2 position = { 0,0 };
	D3DXVECTOR2 force = { 0,0 };
	TextureInfo info;
	BoxCollider collider;
	bool destroy = false;
	int z = 0;
	RECT rc = { 0,0,0,0 };
	std::wstring name = L"";

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void Release();

	void AddForce();

	void DrawSelf();

	GameObject* PlaceMeeting(D3DXVECTOR2 vector, int layer = Layer::DEFAULT);
	bool IsClicked(MouseManager::Key key = MouseManager::Key::ANY);

	void SetTexture(std::wstring path, D3DXVECTOR2 textureSize, D3DXVECTOR2 textureScale = { 1,1 });;
	void SetCollider(D3DXVECTOR2 colliderSize, int layer);

	RECT* GetRect(D3DXVECTOR2 vector = { 0,0 });
};

