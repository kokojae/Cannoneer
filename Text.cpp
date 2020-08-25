#include "DXUT.h"
#include "Text.h"
#include "Cannoneer.h"

void Text::Init()
{
	info.color = D3DCOLOR_ARGB(alpha, 0, 0, 0);
	z = 100;
}

void Text::Render()
{
	info.color = D3DCOLOR_ARGB(alpha, 0, 0, 0);
	GraphicManager::OutLineTextRender(text, info, position);

}

void Text::SetText(std::wstring a_text, D3DXVECTOR2 scale, bool isCamOn)
{
	text = a_text;
	info.scale = scale;
	info.cameraOn = isCamOn;
}
