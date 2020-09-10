#include "DXUT.h"
#include "SceneManager.h"
#include "Cannoneer.h"

SceneManager::Scene SceneManager::currentScene = SceneManager::Scene::TITLE;

void SceneManager::LoadScene(Scene scene)
{
	currentScene = scene;

	Camera::Reset();

	ObjectManager::Clear();

	SoundManager::StopAllSFX();

	switch (scene)
	{
	case SceneManager::Scene::TITLE:
		break;
	case SceneManager::Scene::STAGE1:
		ObjectManager::Instantiate<BackGround>({ 2880,0 });

		ObjectManager::Instantiate<Player>();
		break;
	case SceneManager::Scene::STAGE2:
		break;
	case SceneManager::Scene::SHOW_RECORD:
		break;
	default:
		break;
	}
}
