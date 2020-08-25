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
	}
}
