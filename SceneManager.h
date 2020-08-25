#pragma once
class SceneManager
{
public:
	static enum class Scene { TITLE, RANK_BOARD, STAGE1, STAGE2, RANK_INPUT };

	static Scene currentScene;

	static void LoadScene(Scene scene);
};

