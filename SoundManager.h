#pragma once
#include <iostream>
#include <map>
#include "SDKsound.h"

class SoundManager
{
public:
	static CSoundManager SFXManager;
	static std::multimap<std::wstring, CSound*> SFXMap;

	static void Init();
	static void Release();

	static CSound* SearchSFX(std::wstring path);
	static void PlaySFX(std::wstring path, bool isBGM = false);
	static void StopSFX(std::wstring path);
	static void StopAllSFX();
};

