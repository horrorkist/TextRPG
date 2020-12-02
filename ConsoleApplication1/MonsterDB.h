#pragma once
#include "Monster.h"
#include <vector>

class MonsterDB
{
public:
	//************************* Monster List *************************
	//(ÀÌ¸§, ¸Æ´ï, ¹Î´ï, ¹æ¾î, °ñµå, °æÇèÄ¡, Ã¼·Â)

	Monster Mouse			{ "»ýÁã", 5, 1, 0, 100, 50, 30, 1 };
	Monster Spider			{ "°Å¹Ì", 7, 3, 0, 140, 70, 40, 1 };
	Monster Bet				{ "¹ÚÁã", 15, 8, 0, 150, 100, 25, 1 };
	Monster Bandit			{ "»êÀû", 30, 20, 3, 700, 400, 80 , 2 };
	Monster Snake			{ "¹ì", 10, 5, 0, 40, 150, 400, 1 };

	Monster Wolf			{ "´Á´ë", 30, 15, 0, 750, 450, 150, 2 };
	Monster Bear			{ "°¥»ö °õ", 40, 20, 0, 1000, 500, 200, 2 };
	Monster Wildboar		{ "¸äµÅÁö", 25, 10, 0, 600, 300, 100, 2 };

	//Monster Wisp;
	//Monster Kobold;
	//Monster Skeleton;

	Monster Goblin			{ "°íºí¸°", 60, 40, 3, 2000, 800, 250, 3 };
	Monster Orc				{ "¿ÀÅ©", 120, 80, 5, 3500, 1000, 400, 3 };
	Monster Ogre			{ "¿À¿ì°Å", 150, 100, 10, 50000, 150, 1000, 4 };

	Monster Dragon			{ "¿À´Ð½Ã¾Æ", 1000, 700, 50, 20000, 50000, 10000, 5 };
	Monster Hatchling		{ "»õ³¢ ¿ë", 300, 200, 30, 25000, 3000, 500, 4 };
	Monster Slime			{ "½½¶óÀÓ", 15, 5, 1, 300, 100, 100, 2 };

	//************************* BattleField2D *************************
	vector<vector<Monster>> BattleFields2D
	{
		{Mouse, Spider, Bet, Snake, Bandit},
		{Wolf, Bear, Wildboar},
		{Goblin, Orc, Ogre},
		{Hatchling, Dragon}
	};

};

