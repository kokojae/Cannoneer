#pragma once
#include "Layer.h"

class BoxCollider
{
public:
	D3DXVECTOR2 size = { 0,0 };
	D3DXVECTOR2 center = { 0,0 };
	bool enable = true;
	int layer = Layer::DEFAULT;
};

