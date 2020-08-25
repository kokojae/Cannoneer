#include "DXUT.h"
#include "TextureManager.h"

std::map<std::wstring, LPDIRECT3DTEXTURE9> TextureManager::textureMap = std::map<std::wstring, LPDIRECT3DTEXTURE9>();

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(std::wstring path)
{
	LPDIRECT3DTEXTURE9 texture;

	if (textureMap.count(path))
	{
		texture = textureMap.find(path)->second;
	}
	else
	{
		D3DXCreateTextureFromFileEx(
			DXUTGetD3D9Device(),
			path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			0,
			NULL,
			NULL,
			&texture);

		textureMap[path] = texture;
	}

	return texture;
}

void TextureManager::ReleaseTexture()
{
	std::map<std::wstring, LPDIRECT3DTEXTURE9>::iterator it = textureMap.begin();

	while (it != textureMap.end())
	{
		it->second->Release();
		textureMap.erase(it++);
	}
}
