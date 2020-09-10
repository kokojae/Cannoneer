#include "DXUT.h"
#include "BackGround.h"
#include "Cannoneer.h"

void BackGround::Init()
{
	switch (SceneManager::currentScene)
	{
	case SceneManager::Scene::STAGE1:
		SetTexture(L"Resource/BackGround/StageBackGround.png", { 5760,1080 });
		break;
	case SceneManager::Scene::STAGE2:
		SetTexture(L"Resource/BackGround/StageBackGround2.png", { 5760,1080 });
		break;
	default:
		break;
	}
	z = -50;
}
