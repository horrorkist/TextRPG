#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Character.h"
#include "Item.h"
#include <ctime>

using namespace std;

//************************* Item List *************************
//iType;  0 : NONE, 1 : 무기, 2 : 투구, 3 : 갑옷, 4: 방패, 5 : 장갑, 6 : 신발
//iRarity;  0 : NONE, 1 : 일반, 2 : 마법, 3 : 희귀, 4 : 레어, 5 : 유니크
//Item(string name, int type, int rarity, int minAtt, int maxAtt, int def, int str, int dex, int intel, int maxHp, int maxMp)
//매개변수 (이름, 종류, 희귀도, 민댐, 맥댐, 방어, 힘, 민, 지, 최대 체력, 최대 마력)

extern Character cPlayer;

extern Item None;

//무기
extern Item LongSword;
extern Item Pickaxe;
extern Item BFSword;
extern Item InfinityEdge;
extern Item DawnBlade;

//투구
extern Item WoodenHelm;
extern Item IronHelm;
extern Item SilverHelm;
extern Item GoldHelm;
extern Item Tiara;

//갑옷
extern Item ClothArmour;
extern Item LeatherArmour;
extern Item Maille;
extern Item PlateArmour;
extern Item MagePlate;

//방패
extern Item WoodenShield;
extern Item IronShield;
extern Item ShildofPurification;
extern Item GoddessShield;
extern Item DragonShield;

//장갑
extern Item Vambrace;
extern Item Gauntlet;
extern Item LeatherGlove;
extern Item GoldenGlove;
extern Item LightGauntlet;

//신발
extern Item BattleBoots;

class StoreManager
{
private:

	int		iStoreLevel = 1; //상점 레벨
	int		iStoreLevelLimit = 9;

	int		iMaxSlots = 3;
	int		iSlotLimit = 10;

	int		iRefCost = 50;
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

	vector<vector<Item>>	ItemList{
		{None},
		{LongSword, WoodenShield, ClothArmour, WoodenHelm},			//일반 등급
		{Pickaxe, IronHelm, LeatherArmour, IronShield},				//마법 등급
		{BFSword, SilverHelm, Maille, ShildofPurification},			//희귀 등급
		{InfinityEdge, GoldHelm, PlateArmour, GoddessShield},		//레어 등급
		{DawnBlade, Tiara, MagePlate, DragonShield}					//유니크 등급
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

