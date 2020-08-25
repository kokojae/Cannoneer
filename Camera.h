#pragma once
class Camera
{
public:
	static D3DXVECTOR2 position;
	static float degree;
	static float scale;
	static D3DXVECTOR2 shake;
	static RECT rc;

	static void Reset();

	static D3DXMATRIX GetCameraMatrix();
	static RECT* GetCameraRect();
};

