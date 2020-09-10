#include "DXUT.h"
#include "WeaponBase.h"
#include "Cannoneer.h"

void WeaponBase::Update()
{
	SetPosition();
	RotationToMouse();
	CompleteReload();
	KeyInput();
	lastTime += DXUTGetElapsedTime();
}

void WeaponBase::RotationToMouse()
{
	diff = MouseManager::position - position;

	GraphicManager::RotatingTexture(&info, diff);
}

void WeaponBase::Fire()
{
	if (nowBullet)
	{
		if (lastTime >= fireBetTime)
		{
			lastTime = 0;

			for (int i = 0; i < bulletCount; i++)
			{
				float x = 0;
				float y = 0;
				if (bulletSpread)
				{
					x = rand() % bulletSpread;
					if (rand() % 2)
						x = -x;
					y = rand() % bulletSpread;
					if (rand() % 2)
						y = -y;
				}
				auto vec = diff + D3DXVECTOR2(x, y);
				auto direction = D3DXVec2Normalize(&D3DXVECTOR2(), &vec);
				ObjectManager::Instantiate<PlayerBullet>(position)->SetBullet(*direction, bulletDamage, bulletSpeed);
			}
			nowBullet--;
			PlayFireSFX();
		}
	}
}

void WeaponBase::Reload()
{
	if (!isReLoad)
	{
		isReLoad = true;
		reloadTime = maxReloadTime;
		PlayReloadSFX();
	}
}

void WeaponBase::CompleteReload()
{
	reloadTime -= DXUTGetElapsedTime();

	if (reloadTime <= 0 && isReLoad)
	{
		nowBullet = maxBullet;
		isReLoad = false;
	}
}

void WeaponBase::SetPosition()
{
	auto pos = *(playerPos);
	pos += { 0, 65 };
	position = pos;
}

void WeaponBase::SetGun(float fireBetTime, int bulletCount, int bulletSpread)
{
	WeaponBase::fireBetTime = fireBetTime;
	WeaponBase::bulletCount = bulletCount;
	WeaponBase::bulletSpread = bulletSpread;
}

void WeaponBase::SetBullet(float bulletDamage, float bulletSpeed)
{
	WeaponBase::bulletDamage = bulletDamage;
	WeaponBase::bulletSpeed = bulletSpeed;
}
