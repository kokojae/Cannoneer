#include "DXUT.h"
#include "GraphicManager.h"
#include "Cannoneer.h"

LPD3DXSPRITE GraphicManager::sprite = nullptr;
ID3DXFont* GraphicManager::font = nullptr;

void GraphicManager::Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);

	D3DXCreateFont(
		DXUTGetD3D9Device(),
		70,
		0,
		FW_BOLD,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Arial",
		&font);
}

void GraphicManager::Render()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	ObjectManager::Render();

	sprite->End();
}

void GraphicManager::Release()
{
	sprite->Release();
	font->Release();
}

void GraphicManager::RotatingTexture(TextureInfo* info, D3DXVECTOR2 direction)
{
	info->degree= D3DXToDegree(atan2(direction.y, direction.x));

	if (info->degree <= -90 && info->degree >= -180)
		info->scale.y = -abs(info->scale.y);
	if (info->degree >= 90 && info->degree <= 180)
		info->scale.y = -abs(info->scale.y);
	if (info->degree > -90 && info->degree < 90)
		info->scale.y = abs(info->scale.y);
}

void GraphicManager::TextureRender(TextureInfo info, D3DXVECTOR2 position)
{
	D3DXMATRIX mat, center, pos, scale, degree;

	D3DXMatrixTranslation(&center, -info.center.x, -info.center.y, 0);
	D3DXMatrixTranslation(&pos, position.x, position.y, 0);
	D3DXMatrixScaling(&scale, info.scale.x, info.scale.y, 1);
	D3DXMatrixRotationZ(&degree, D3DXToRadian(info.degree));

	mat = center * scale * degree * pos;

	if (info.cameraOn)
		mat *= Camera::GetCameraMatrix();

	sprite->SetTransform(&mat);

	// 도트겜에 사용
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	DXUTGetD3D9Device()->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	RECT rc = {
		(LONG)info.index * (LONG)info.size.x,
		0,
		(LONG)(info.index + 1) * (LONG)info.size.x,
		(LONG)info.size.y
	};

	sprite->Draw(info.texture, &rc, NULL, NULL, info.color);
}

void GraphicManager::TextRender(std::wstring text, TextureInfo info, D3DXVECTOR2 position)
{
	D3DXMATRIX mat, sca, pos;

	D3DXMatrixScaling(&sca, info.scale.x, info.scale.x, 1);
	D3DXMatrixTranslation(&pos, position.x, position.y, 0);

	mat = sca * pos;

	if (info.cameraOn)
		mat *= Camera::GetCameraMatrix();

	sprite->SetTransform(&mat);

	font->DrawText(sprite, text.c_str(), -1, NULL, DT_NOCLIP, info.color);
}

void GraphicManager::OutLineTextRender(std::wstring text, TextureInfo info, D3DXVECTOR2 position)
{
	D3DXCOLOR temp = info.color;

	int a = 255 * info.color.a;
	int r = 255 - (255 * info.color.r);
	int g = 255 - (255 * info.color.g);
	int b = 255 - (255 * info.color.b);
	info.color = D3DCOLOR_ARGB(255, 255, 255, 255);
	GraphicManager::TextRender(text, info, { position.x + 1,position.y });
	GraphicManager::TextRender(text, info, { position.x + 1,position.y + 1 });
	GraphicManager::TextRender(text, info, { position.x,position.y + 1 });
	GraphicManager::TextRender(text, info, { position.x - 1,position.y + 1 });
	GraphicManager::TextRender(text, info, { position.x - 1,position.y });
	GraphicManager::TextRender(text, info, { position.x - 1,position.y - 1 });
	GraphicManager::TextRender(text, info, { position.x,position.y - 1 });
	GraphicManager::TextRender(text, info, { position.x + 1,position.y - 1 });
	
	info.color = temp;
	GraphicManager::TextRender(text, info, position);
}
