#pragma once
class SceneManager
{
public:
	static enum class Scene { TITLE, STAGE1, STAGE2, SHOW_RECORD};

	static Scene currentScene;

	static void LoadScene(Scene scene);
};

