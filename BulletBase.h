#pragma once
#include "GameObject.h"
class BulletBase :
    public GameObject
{
public:
	float damage = 0;

	void Update()override;

	void Collider();
	void Destroy();

	virtual void Process(GameObject* damegeedObject) = 0;

	void SetBullet(D3DXVECTOR2 a_direction, float damage, float speed);
};

