#pragma once
#include <string>
#include <iostream>
#include "Item.h"
#include "ItemDB.h"

using namespace std;

extern ItemDB itemDB;

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

	Item Equipment[7] = { itemDB.None, itemDB.None, itemDB.None, itemDB.None, itemDB.None, itemDB.None, itemDB.None };

public:

	void CreateNewChar();
	void ShowCharStats() const;
	void ShowCharEquipments() const;

	friend class StoreManager;
	friend class SystemManager;
	friend class BattleManager;
	friend class Item;
};

