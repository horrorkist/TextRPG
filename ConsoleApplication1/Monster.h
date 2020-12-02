#pragma once
#include "Character.h"
#include <vector>

class Monster : public Character
{
private:
	string					strRace;

public:
	int						iMonsterRank;

	int						iDropChance = 40;

	vector<vector<int>>		vDropChance2D
	{
		{0},
		{0, 50, 50, 0, 0, 0},			//¸ó½ºÅÍ ·©Å© 1
		{0, 30, 60, 10, 0, 0},			//¸ó½ºÅÍ ·©Å© 2
		{0, 0, 50, 30, 20, 0},			//¸ó½ºÅÍ ·©Å© 3
		{0, 0, 0, 20, 60, 20},			//¸ó½ºÅÍ ·©Å© 4
		{0, 0, 0, 0, 0, 100}			//¸ó½ºÅÍ ·©Å© 5
	};

	vector<vector<int>>		vDropTableCode2D
	{
		{ 0 },
		{ 1, 6, 11, 16 },					//ÀÏ¹Ý µî±Þ
		{ 2, 7, 12, 17 },					//¸¶¹ý µî±Þ
		{ 3, 8, 13, 18 },					//Èñ±Í µî±Þ
		{ 4, 9, 14, 19 },					//·¹¾î µî±Þ
		{ 5, 10, 15, 20 }					//À¯´ÏÅ© µî±Þ
	};

	Monster(string , int , int , int , int , int, int, int);
	void ShowCharStats() const;
};
