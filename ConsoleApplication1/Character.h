#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Item.h"
#include "ItemDB.h"

using namespace std;

class Character
{
protected:

	string	sName;
	int		iMaxHp;
	int		iHp;
	int		iMaxAtt;
	int		iMinAtt;
	int		iDef;
	int		iGold;
	int		iExp;

	int		iMaxMp;
	int		iMp;
	int		iLevel;
	int		iRqExp;
	int		iDodge;
	int		iStr;
	int		iDex;
	int		iInt;

	Item Equipment[7];

public:

	void CreateNewChar();
	void ShowCharStats() const;
	void SetUsingData(string str);
	string GetDataString();
	void ShowCharEquipments() const;
	void GetItemCodes();

	friend class StoreManager;
	friend class SystemManager;
	friend class BattleManager;
	friend class Item;
};

