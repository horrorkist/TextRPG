#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Character.h"
#include "Item.h"
#include <ctime>

using namespace std;

class StoreManager
{
private:

	int		iStoreLevel = 1; //���� ����
	int		iStoreLevelLimit = 9;

	int		iMaxSlots = 3;
	int		iSlotLimit = 10;

	int		iRefCost = 0;
	int		iStoreLevelUpCost = 500;
	int		iAddSlotCost = 100;

	int		Odds[10][6] = {
		{0, 0, 0, 0, 0, 0},
		{0, 90, 10, 0, 0, 0},			//1����
		{0, 75, 20, 5, 0, 0},			//2����
		{0, 60, 30, 10, 0, 0},			//3����
		{0, 55, 30, 10, 5, 0},		//4����
		{0, 45, 35, 15, 5, 0},		//5����
		{0, 35, 35, 20, 10, 0},		//6����
		{0, 25, 30, 30, 15, 0},		//7����
		{0, 15, 25, 30, 25, 5},		//8����
		{0, 10, 25, 15, 35, 15}		//9����
	};

	Item	Slot[100];


public:

	bool isAllSlotsEmpty() const;

	void ShowStoreMenu();

	void ShowStoreList() const;

	void FillSlot(int slotNum);

	void StoreUpgrade();

	void StoreRefesh();
};

