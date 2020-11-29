#pragma once
#include "Monster.h"
#include <vector>

class MonsterDB
{
public:
	//************************* Monster List *************************
	//(ÀÌ¸§, ¸Æ´ï, ¹Î´ï, ¹æ¾î, °ñµå, °æÇèÄ¡, Ã¼·Â)

	Monster Mouse			{ "»ýÁã", 5, 1, 0, 10, 5, 30, 1 };
	Monster Spider			{ "°Å¹Ì", 7, 3, 0, 14, 7, 40, 1 };
	Monster Bet				{ "¹ÚÁã", 15, 8, 0, 15, 10, 25, 1 };
	Monster Bandit			{ "»êÀû", 30, 20, 3, 70, 40, 80 , 2 };
	Monster Snake			{ "¹ì", 10, 5, 0, 40, 15, 40, 1 };

	Monster Wolf			{ "´Á´ë", 30, 15, 0, 75, 45, 150, 2 };
	Monster Bear			{ "°¥»ö °õ", 40, 20, 0, 100, 50, 200, 2 };
	Monster Wildboar		{ "¸äµÅÁö", 25, 10, 0, 60, 30, 100, 2 };

	//Monster Wisp;
	//Monster Kobold;
	//Monster Skeleton;

	Monster Goblin			{ "°íºí¸°", 60, 40, 3, 200, 80, 250, 3 };
	Monster Orc				{ "¿ÀÅ©", 120, 80, 5, 350, 100, 400, 3 };
	Monster Ogre			{ "¿À¿ì°Å", 150, 100, 10, 500, 150, 1000, 4 };

	Monster Dragon			{ "¿À´Ð½Ã¾Æ", 1000, 700, 50, 20000, 5000, 10000, 5 };
	Monster Hatchling		{ "»õ³¢ ¿ë", 300, 200, 30, 2500, 300, 500, 4 };
	Monster Slime			{ "½½¶óÀÓ", 15, 5, 1, 30, 10, 100, 2 };

	//************************* BattleField2D *************************
	vector<vector<Monster>> BattleFields2D
	{
		{Mouse, Spider, Bet, Snake, Bandit},
		{Wolf, Bear, Wildboar},
		{Goblin, Orc, Ogre},
		{Hatchling, Dragon}
	};

};

