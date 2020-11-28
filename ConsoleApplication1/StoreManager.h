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

	int iStoreLevel = 1; //���� ����
	int iMaxSlots = 3;

	int Odds[10][6] = {
		{0, 0, 0, 0, 0, 0},
		{0, 90, 100, 0, 0, 0},			//1����
		{0, 75, 95, 100, 0, 0},			//2����
		{0, 60, 90, 100, 0, 0},			//3����
		{0, 55, 85, 95, 100, 0},		//4����
		{0, 45, 80, 95, 100, 0},		//5����
		{0, 35, 70, 90, 100, 0},		//6����
		{0, 25, 55, 85, 100, 0},		//7����
		{0, 15, 40, 70, 95, 100},		//8����
		{0, 10, 35, 60, 85, 100}		//9����
	};

	vector<vector<Item>> ItemList{
		{None},
		{LongSword, WoodenShield, ClothArmour, WoodenHelm},			//�Ϲ� ���
		{Pickaxe, IronHelm, LeatherArmour, IronShield},				//���� ���
		{BFSword, SilverHelm, Maille, ShildofPurification},			//��� ���
		{InfinityEdge, GoldHelm, PlateArmour, GoddessShield},		//���� ���
		{DawnBlade, Tiara, MagePlate, DragonShield}					//����ũ ���
	};

	Item Slot[100];


public:

	bool isAllSlotsEmpty() const;

	void ShowStoreMenu();

	void ShowStoreList() const;

	void FillSlot(int slotNum);

	void StoreUpgrade();

	void StoreRefesh();
};

