#pragma once
class TextureInfo
{
public:
	LPDIRECT3DTEXTURE9 texture = nullptr;
	D3DXVECTOR2 size = { 0,0 };
	D3DXVECTOR2 center = { 0,0 };
	D3DXVECTOR2 scale= { 0,0 };
	int index = 0;
	float degree = 0;
	D3DXCOLOR color = D3DCOLOR_ARGB(255, 255, 255, 255);
	bool cameraOn = true;
};

