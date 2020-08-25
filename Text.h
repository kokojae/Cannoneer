#pragma once
#include "GameObject.h"
class Text :
    public GameObject
{
public:
	std::wstring text = L"";
	int alpha = 255;

	virtual void Init()override;
	virtual void Render()override;

	void SetText(std::wstring a_text, D3DXVECTOR2 scale = { 1,1 }, bool isCamOn = true);
};

