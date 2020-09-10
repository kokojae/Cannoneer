#include "DXUT.h"
#include "Player.h"
#include "Cannoneer.h"

void Player::Init()
{
	SetTexture(L"Resource/Player/Player.png", { 153,149 });
	SetCollider({ 153,149 }, Layer::PLAYER);
	z = 50;

	auto inst = ObjectManager::Instantiate<Sniper>(position);
	inst->SetTrans(&position);
	inst->SetGun(0.5);
	inst->SetBullet(10, 50);

	if (position.x == 0)
		position.x = 200;

	camera_position = position;
}

void Player::Update()
{
	Move();
	Evasion();
	Collider();
	AddForce();
}

void Player::LateUpdate()
{
	MoveLimit();
	CameraFollow();
}

void Player::Move()
{
	if (GetAsyncKeyState('W'))
	{
		force.y -= speed * DXUTGetElapsedTime();
		if (force.y <= -speed)
			force.y = -speed;
	}
	if (GetAsyncKeyState('S'))
	{
		force.y += speed * DXUTGetElapsedTime();
		if (force.y >= speed)
			force.y = speed;
	}
	if (!GetAsyncKeyState('W') && !GetAsyncKeyState('S'))
	{
		force.y -= force.y / drag;
	}

	if (GetAsyncKeyState('A'))
	{
		force.x -= speed * DXUTGetElapsedTime();
		if (force.x <= -speed)
			force.x = -speed;
	}
	if (GetAsyncKeyState('D'))
	{
		force.x += speed * DXUTGetElapsedTime();
		if (force.x >= speed)
			force.x = speed;
	}
	if (!GetAsyncKeyState('A') && !GetAsyncKeyState('D'))
	{
		force.x -= force.x / drag;
	}
}

void Player::Collider()
{
	if (PlaceMeeting({ force.x,0 }, Layer::ENEMY))
	{
		force.x = 0;
	}
	if (PlaceMeeting({ 0,force.y }, Layer::ENEMY))
	{
		force.y = 0;
	}
}

void Player::Evasion()
{
}

void Player::MoveLimit()
{
	if (position.x - info.center.x <= 0)
	{
		position.x = info.center.x;
		if (force.x < 0)
			force.x = 0;
	}
	if (position.x + info.center.x >= 5760)
	{
		position.x = 5760 - info.center.x;
		if (force.x > 0)
			force.x = 0;
	}

	if (position.y + info.center.y >= 540)
	{
		position.y = 540 - info.center.y;
		if (force.y > 0)
			force.y = 0;
	}
	if (position.y + info.center.y <= -150)
	{
		position.y = -150 - info.center.y;
		if (force.y < 0)
			force.y = 0;
	}
}

void Player::CameraFollow()
{
	camera_position.x += (position.x + 450 - camera_position.x) / drag;
	camera_position.y += (position.y - camera_position.y) / drag;

	if (camera_position.x < SCREEN_WIDTH / 2)
		camera_position.x = SCREEN_WIDTH / 2;
	if (camera_position.x > 5760 - SCREEN_WIDTH / 2)
		camera_position.x = 5760 - SCREEN_WIDTH / 2;

	if (camera_position.y + SCREEN_HEIGHT / 2 > 540)
		camera_position.y = 540 - SCREEN_HEIGHT / 2;
	if (camera_position.y - SCREEN_HEIGHT / 2 < -540)
		camera_position.y = -540 + SCREEN_HEIGHT / 2;

	Camera::position = camera_position + D3DXVECTOR2((rand() % (int)Camera::shake.x - (int)Camera::shake.x / 2), (rand() % (int)Camera::shake.y - (int)Camera::shake.y / 2));

	Camera::scale += (1 - Camera::scale) / 10;
}
