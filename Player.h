#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
	float maxHp = 100;
	float hp = maxHp;

	float speed = 7;
	float drag = speed * 2;

	bool isAntibiotic = false;
	float maxAntibioticTime = 3;
	float antibioticTime = maxAntibioticTime;

	bool isVaccine = false;
	float maxVaccineTime = 3;
	float vaccineTime = maxVaccineTime;

	bool isEvasion = false;
	float maxEvasionTime = 0.5;
	float evasionTime = maxEvasionTime;

	D3DXVECTOR2 camera_position = { 0,0 };

	void Init()override;
	void Update()override;
	void LateUpdate()override;

	void Move();
	void Evasion();

	void Collider();

	void MoveLimit();
	void CameraFollow();
};

