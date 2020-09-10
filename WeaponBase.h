#pragma once
#include "GameObject.h"
class WeaponBase :
    public GameObject
{
public:

	D3DXVECTOR2* playerPos = nullptr;
	D3DXVECTOR2 diff = { 0,0 };

	int bulletCount = 0;
	int bulletSpread = 0;

	float fireBetTime = 0;
	float lastTime = 0;

	int maxBullet = 0;
	int nowBullet = maxBullet;

	bool isReLoad = false;
	float maxReloadTime = 2;
	float reloadTime = 0;

	float bulletDamage = 10;
	float bulletSpeed = 0;

	void Update() override;

	virtual void KeyInput() = 0;
	virtual void PlayFireSFX() = 0;
	virtual void PlayReloadSFX() = 0;

	void Fire();
	void Reload();
	void CompleteReload();

	void RotationToMouse();
	void SetPosition();

	void SetTrans(D3DXVECTOR2* pos) { playerPos = pos; }
	void SetGun(float fireBetTime, int bulletCount = 1, int bulletSpread = 0);
	void SetBullet(float bulletDamage, float bulletSpeed);
};

