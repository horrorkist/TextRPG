#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Character.h"
#include "Item.h"
#include <ctime>

using namespace std;

//************************* Item List *************************
//iType;  0 : NONE, 1 : ����, 2 : ����, 3 : ����, 4: ����, 5 : �尩, 6 : �Ź�
//iRarity;  0 : NONE, 1 : �Ϲ�, 2 : ����, 3 : ���, 4 : ����, 5 : ����ũ
//Item(string name, int type, int rarity, int minAtt, int maxAtt, int def, int str, int dex, int intel, int maxHp, int maxMp)
//�Ű����� (�̸�, ����, ��͵�, �δ�, �ƴ�, ���, ��, ��, ��, �ִ� ü��, �ִ� ����)

extern Character cPlayer;

extern Item None;

//����
extern Item LongSword;
extern Item Pickaxe;
extern Item BFSword;
extern Item InfinityEdge;
extern Item DawnBlade;

//����
extern Item WoodenHelm;
extern Item IronHelm;
extern Item SilverHelm;
extern Item GoldHelm;
extern Item Tiara;

//����
extern Item ClothArmour;
extern Item LeatherArmour;
extern Item Maille;
extern Item PlateArmour;
extern Item MagePlate;

//����
extern Item WoodenShield;
extern Item IronShield;
extern Item ShildofPurification;
extern Item GoddessShield;
extern Item DragonShield;

//�尩
extern Item Vambrace;
extern Item Gauntlet;
extern Item LeatherGlove;
extern Item GoldenGlove;
extern Item LightGauntlet;

//�Ź�
extern Item BattleBoots;

class StoreManager
{
private:

	int		iStoreLevel = 1; //���� ����
	int		iStoreLevelLimit = 9;

	int		iMaxSlots = 3;
	int		iSlotLimit = 10;

	int		iRefCost = 50;
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

	vector<vector<Item>>	ItemList{
		{None},
		{LongSword, WoodenShield, ClothArmour, WoodenHelm},			//�Ϲ� ���
		{Pickaxe, IronHelm, LeatherArmour, IronShield},				//���� ���
		{BFSword, SilverHelm, Maille, ShildofPurification},			//��� ���
		{InfinityEdge, GoldHelm, PlateArmour, GoddessShield},		//���� ���
		{DawnBlade, Tiara, MagePlate, DragonShield}					//����ũ ���
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

