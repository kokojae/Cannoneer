#include "DXUT.h"
#include "MouseManager.h"

D3DXVECTOR2 MouseManager::position = { 0,0 };
bool MouseManager::leftBtn = false;
bool MouseManager::middleBtn = false;
bool MouseManager::rightBtn = false;
RECT MouseManager::rc = { 0,0,0,0 };

RECT* MouseManager::GetMusRect()
{
	LONG x = static_cast<LONG>(position.x);
	LONG y = static_cast<LONG>(position.y);

	rc = { x - 1,y - 1,x + 1,y + 1 };

	return &rc;
}
