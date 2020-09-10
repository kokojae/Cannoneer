#pragma once
#include "BulletBase.h"
class PlayerBullet :
    public BulletBase
{
public:
	void Init()override;

	void Process(GameObject* damegeedObject);
};

