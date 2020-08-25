#include "DXUT.h"
#include "GameObject.h"
#include "Cannoneer.h"

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	DrawSelf();
}

void GameObject::Release()
{
}

void GameObject::AddForce()
{
	position += force;
}

void GameObject::DrawSelf()
{
	GraphicManager::TextureRender(info, position);
}

GameObject* GameObject::PlaceMeeting(D3DXVECTOR2 vector, int layer)
{
	collider.enable = false;
	GameObject* inst = ObjectManager::ColliderCheck(GetRect(vector), layer);
	collider.enable = true;
	return inst;
}

bool GameObject::IsClicked(MouseManager::Key key)
{
	switch (key)
	{
	case MouseManager::Key::LEFT:
		if (MouseManager::leftBtn) break;
		else return false;
	case MouseManager::Key::MIDDLE:
		if (MouseManager::middleBtn) break;
		else return false;
	case MouseManager::Key::RIGHT:
		if (MouseManager::rightBtn) break;
		else return false;
	case MouseManager::Key::ANY:
		break;
	default:
		break;
	}

	return IntersectRect(&RECT(), GetRect(), MouseManager::GetMusRect());
}

void GameObject::SetTexture(std::wstring path, D3DXVECTOR2 textureSize, D3DXVECTOR2 textureScale)
{
	info.texture = TextureManager::LoadTexture(path);
	info.size = textureSize;
	info.center = info.size / 2;
	info.scale = textureScale;
}

void GameObject::SetCollider(D3DXVECTOR2 colliderSize, int layer)
{
	collider.size = colliderSize;
	collider.center = collider.size / 2;
	collider.layer = layer;
}

RECT* GameObject::GetRect(D3DXVECTOR2 vector)
{
	rc = {
		static_cast<LONG>((position - collider.center + vector).x),
		static_cast<LONG>((position - collider.center + vector).y),
		static_cast<LONG>((position - collider.center + vector + collider.size).x),
		static_cast<LONG>((position - collider.center + vector + collider.size).y),
	};

	return &rc;
}
