#pragma once
#include "Monster.h"
#include <vector>

class MonsterDB
{
public:
	//************************* Monster List *************************
	//(�̸�, �ƴ�, �δ�, ���, ���, ����ġ, ü��)

	Monster Mouse			{ "����", 5, 1, 0, 10, 5, 30 };
	Monster Spider			{ "�Ź�", 7, 3, 0, 14, 7, 40 };
	Monster Bet				{ "����", 15, 8, 0, 15, 10, 25 };
	Monster Bandit			{ "����", 30, 20, 3, 70, 40, 80 };
	Monster Snake			{ "��", 10, 5, 0, 40, 15, 40 };

	Monster Wolf			{ "����", 30, 15, 0, 75, 45, 150 };
	Monster Bear			{ "���� ��", 40, 20, 0, 100, 50, 200 };
	Monster Wildboar		{ "�����", 25, 10, 0, 60, 30, 100 };

	//Monster Wisp;
	//Monster Kobold;
	//Monster Skeleton;
	Monster Goblin			{ "���", 60, 40, 3, 200, 80, 250 };
	Monster Orc				{ "��ũ", 120, 80, 5, 350, 100, 400 };
	Monster Ogre			{ "�����", 150, 100, 10, 500, 150, 1000 };

	Monster Dragon			{ "���нþ�", 1000, 700, 50, 20000, 5000, 10000 };
	Monster Hatchling		{ "���� ��", 300, 200, 30, 2500, 300, 500 };
	Monster Slime			{ "������", 15, 5, 1, 30, 10, 100 };

	//************************* BattleField2D *************************
	vector<vector<Monster>> BattleFields2D
	{
		{Mouse, Spider, Bet, Snake, Bandit},
		{Wolf, Bear, Wildboar},
		{Goblin, Orc, Ogre},
		{Hatchling, Dragon}
	};
};

