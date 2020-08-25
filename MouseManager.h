#pragma once
class MouseManager
{
public:
	enum class Key { LEFT, MIDDLE, RIGHT, ANY };

	static D3DXVECTOR2 position;
	static bool leftBtn;
	static bool middleBtn;
	static bool rightBtn;
	static RECT rc;

	static RECT* GetMusRect();
};

