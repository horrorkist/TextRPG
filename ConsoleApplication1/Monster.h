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
		{0, 50, 50, 0, 0, 0},			//몬스터 랭크 1
		{0, 30, 60, 10, 0, 0},			//몬스터 랭크 2
		{0, 0, 50, 30, 20, 0},			//몬스터 랭크 3
		{0, 0, 0, 20, 60, 20},			//몬스터 랭크 4
		{0, 0, 0, 0, 0, 100}			//몬스터 랭크 5
	};

	vector<vector<int>>		vDropTableCode2D
	{
		{ 0 },
		{ 1, 6, 11, 16 },					//일반 등급
		{ 2, 7, 12, 17 },					//마법 등급
		{ 3, 8, 13, 18 },					//희귀 등급
		{ 4, 9, 14, 19 },					//레어 등급
		{ 5, 10, 15, 20 }					//유니크 등급
	};

	Monster(string , int , int , int , int , int, int, int);
	void ShowCharStats() const;
};
