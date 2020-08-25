#pragma once
#include <iostream>
#include "TextureInfo.h"

class GraphicManager
{
public:
	static LPD3DXSPRITE sprite;
	static ID3DXFont* font;

	static void Init();
	static void Render();
	static void Release();
	static void TextureRender(TextureInfo info, D3DXVECTOR2 position);
	static void TextRender(std::wstring text, TextureInfo info, D3DXVECTOR2 position);
	static void OutLineTextRender(std::wstring text, TextureInfo info, D3DXVECTOR2 position);
};

