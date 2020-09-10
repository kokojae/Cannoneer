#pragma once
class Layer
{
public:
	const static int DEFAULT	= 1 << 1;
	const static int PLAYER		= 1 << 2;
	const static int ENEMY		= 1 << 3;
	const static int BLANK6		= 1 << 4;
	const static int SHIELD		= 1 << 5;
	const static int BLANK4		= 1 << 6;
	const static int PLAYER_BULLET = 1 << 7;
	const static int ENEMY_BULLET = 1 << 8;
	const static int WEAPON		= 1 << 9;
};

