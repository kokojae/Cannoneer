#include "DXUT.h"
#include "PlayerBullet.h"
#include "Cannoneer.h"

void PlayerBullet::Init()
{
	SetTexture(L"Resource/Bullet/PlayerBullet.png", { 183,78 });
	SetCollider({ 183,78 }, Layer::PLAYER_BULLET);
	z = 10;
}

void PlayerBullet::Process(GameObject* damegeedObject)
{
	auto inst = dynamic_cast<EnemyBase*>(damegeedObject);
	if (inst != nullptr)
	{
		destroy = true;
	}
}
