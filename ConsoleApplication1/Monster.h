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
		{0, 50, 50, 0, 0, 0},			//���� ��ũ 1
		{0, 30, 60, 10, 0, 0},			//���� ��ũ 2
		{0, 0, 50, 30, 20, 0},			//���� ��ũ 3
		{0, 0, 0, 20, 60, 20},			//���� ��ũ 4
		{0, 0, 0, 0, 0, 100}			//���� ��ũ 5
	};

	vector<vector<int>>		vDropTableCode2D
	{
		{ 0 },
		{ 1, 6, 11, 16 },					//�Ϲ� ���
		{ 2, 7, 12, 17 },					//���� ���
		{ 3, 8, 13, 18 },					//��� ���
		{ 4, 9, 14, 19 },					//���� ���
		{ 5, 10, 15, 20 }					//����ũ ���
	};

	Monster(string , int , int , int , int , int, int, int);
	void ShowCharStats() const;
};
