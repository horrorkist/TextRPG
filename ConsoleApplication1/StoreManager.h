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

	int storelevel = 1; //상점 레벨

	Item Slot1;
	Item Slot2;
	Item Slot3;
	int		iStoreLevel = 1; //상점 레벨
	int		iStoreLevelLimit = 9;

	int		iMaxSlots = 3;
	int		iSlotLimit = 10;

	int		iRefCost = 0;
	int		iStoreLevelUpCost = 500;
	int		iAddSlotCost = 100;

	int		Odds[10][6] = {
		{0, 0, 0, 0, 0, 0},
		{0, 90, 10, 0, 0, 0},			//1레벨
		{0, 75, 20, 5, 0, 0},			//2레벨
		{0, 60, 30, 10, 0, 0},			//3레벨
		{0, 55, 30, 10, 5, 0},		//4레벨
		{0, 45, 35, 15, 5, 0},		//5레벨
		{0, 35, 35, 20, 10, 0},		//6레벨
		{0, 25, 30, 30, 15, 0},		//7레벨
		{0, 15, 25, 30, 25, 5},		//8레벨
		{0, 10, 25, 15, 35, 15}		//9레벨
	};

	Item	Slot[100];


public:

	void StoreMenu() const;

	void ShowStoreList() const;

	bool isAllSlotsEmpty() const;

	void ShowStoreMenu();


	void FillSlot(int slotNum);

	void StoreUpgrade();

	void StoreRefesh();
};

