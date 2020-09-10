#include "DXUT.h"
#include "BulletBase.h"
#include "Cannoneer.h"

void BulletBase::Update()
{
	AddForce();
	Collider();
	Destroy();
}

void BulletBase::Collider()
{
	auto inst = PlaceMeeting({ 0,0 }, Layer::PLAYER | Layer::ENEMY | Layer::SHIELD);
	if (inst != nullptr)
		Process(inst);
}

void BulletBase::Destroy()
{
	if (position.x + info.center.x < Camera::position.x - SCREEN_WIDTH / 2)
		destroy = true;
	if (position.x - info.center.x > Camera::position.x + SCREEN_WIDTH / 2)
		destroy = true;
	if (position.y + info.center.y < Camera::position.y - SCREEN_HEIGHT / 2)
		destroy = true;
	if (position.y - info.center.y > Camera::position.y + SCREEN_HEIGHT / 2)
		destroy = true;
}

void BulletBase::SetBullet(D3DXVECTOR2 a_direction, float a_damage, float speed)
{
	D3DXVec2Normalize(&force, &a_direction);
	force *= speed;
	damage = a_damage;

	GraphicManager::RotatingTexture(&info, a_direction);
}
