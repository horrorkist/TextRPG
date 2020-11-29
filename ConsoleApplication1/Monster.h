#pragma once
#include "Character.h"

class Monster : public Character
{
private:
	string					strRace;
	int						iMonsterRank;

	vector<vector<int>>		DropChance2D;
	vector<vector<Item>>	DropTable;
public:
	Monster(string , int , int , int , int , int, int);
	void ShowCharStats() const;
};
