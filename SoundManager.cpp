#include "DXUT.h"
#include "SoundManager.h"

CSoundManager SoundManager::SFXManager = CSoundManager();
std::multimap<std::wstring, CSound*> SoundManager::SFXMap = std::multimap<std::wstring, CSound*>();

void SoundManager::Init()
{
	SFXManager.Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	SFXManager.SetPrimaryBufferFormat(2, 22050, 16);
}

void SoundManager::Release()
{
	std::multimap<std::wstring, CSound*>::iterator it = SFXMap.begin();

	while (it != SFXMap.end())
	{
		it->second->Stop();
		it->second->Reset();
		SFXMap.erase(it++);
	}
}

CSound* SoundManager::SearchSFX(std::wstring path)
{
	CSound* sfx = nullptr;
	auto pair = SFXMap.equal_range(path);

	for (auto it = pair.first; it != pair.second; it++)
	{
		if (it._Ptr->_Myval.second->IsSoundPlaying())
			continue;
		else
			return sfx = it._Ptr->_Myval.second;
	}

	SFXManager.Create(&sfx, const_cast<LPWSTR>(path.c_str()));
	SFXMap.insert(std::pair<std::wstring, CSound*>(path, sfx));

	return sfx;
}

void SoundManager::PlaySFX(std::wstring path, bool isBGM)
{
	CSound* sfx = SearchSFX(path);

	if (isBGM)
		sfx->Play(0, DSBPLAY_LOOPING);
	else
		sfx->Play(0, NULL);
}

void SoundManager::StopSFX(std::wstring path)
{
	auto pair = SFXMap.equal_range(path);

	for (auto it = pair.first; it != pair.second; it++)
	{
		it._Ptr->_Myval.second->Stop();
		it._Ptr->_Myval.second->Reset();
	}
}

void SoundManager::StopAllSFX()
{
	std::map<std::wstring, CSound*>::iterator it = SFXMap.begin();

	while (it != SFXMap.end())
	{
		it->second->Stop();
		it->second->Reset();
		it++;
	}
}
