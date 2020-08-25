#include "DXUT.h"
#include "Camera.h"
#include "Cannoneer.h"

D3DXVECTOR2 Camera::position = { 0,0 };
float Camera::degree = 0;
float Camera::scale = 1;
D3DXVECTOR2 Camera::shake = { 1,1 };
RECT Camera::rc = { 0,0,0,0 };

void Camera::Reset()
{
	position = { 0,0 };
	degree = 0;
	scale = 1;
	shake = { 1,1 };
	rc = { 0,0,0,0 };
}

D3DXMATRIX Camera::GetCameraMatrix()
{
	D3DXMATRIX mat, positionMat, rotationMat, scaleMat, screenMat;

	D3DXMatrixTranslation(&positionMat, -position.x, -position.y, 0);
	D3DXMatrixRotationZ(&rotationMat, D3DXToRadian(degree));
	D3DXMatrixScaling(&scaleMat, 1 / scale, 1 / scale, 1);
	D3DXMatrixTranslation(&screenMat, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

	mat = positionMat * scaleMat * rotationMat * screenMat;

	return mat;
}

RECT* Camera::GetCameraRect()
{
	rc = {
		static_cast<LONG>(position.x - SCREEN_WIDTH / 2),
		static_cast<LONG>(position.y - SCREEN_HEIGHT / 2),
		static_cast<LONG>(position.x + SCREEN_WIDTH / 2),
		static_cast<LONG>(position.y + SCREEN_HEIGHT / 2)
	};

	return &rc;
}
