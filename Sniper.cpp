#include "DXUT.h"
#include "Sniper.h"
#include "Cannoneer.h"

void Sniper::Init()
{
	SetTexture(L"Resource/Player/Gun.png", { 711, 191 }, { 0.5,0.5 });

	z = 70;
	collider.layer = Layer::WEAPON;

	nowBullet = maxBullet = 6;
}

void Sniper::KeyInput()
{
	static bool isFirePush = false;
	if (MouseManager::leftBtn && !isFirePush)
	{
		Fire();
		isFirePush = true;
	}
	else if (!MouseManager::leftBtn)
	{
		isFirePush = false;
	}

	if (MouseManager::rightBtn)
	{
		Reload();
	}
}

void Sniper::PlayFireSFX()
{
}

void Sniper::PlayReloadSFX()
{
}
