#pragma once
#include <iostream>
#include <map>

class TextureManager
{
public:
	static std::map<std::wstring, LPDIRECT3DTEXTURE9> textureMap;

	static LPDIRECT3DTEXTURE9 LoadTexture(std::wstring path);
	static void ReleaseTexture();
};

