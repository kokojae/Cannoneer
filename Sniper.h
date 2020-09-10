#pragma once
#include "WeaponBase.h"
class Sniper :
    public WeaponBase
{
public:
	void Init() override;

	void KeyInput() override;
	void PlayFireSFX() override;
	void PlayReloadSFX() override;
};

