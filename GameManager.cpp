#include "DXUT.h"
#include "GameManager.h"
#include "Cannoneer.h"

void GameManager::Init()
{
	GraphicManager::Init();
	SoundManager::Init();
	SceneManager::LoadScene(SceneManager::Scene::STAGE1);
}

void GameManager::Update()
{
	ObjectManager::Update();
}

void GameManager::LateUpdate()
{
	ObjectManager::LateUpdate();
}

void GameManager::Render()
{
	GraphicManager::Render();
}

void GameManager::Release()
{
	SoundManager::Release();
	ObjectManager::Release();
	TextureManager::ReleaseTexture();
	GraphicManager::Release();
}
