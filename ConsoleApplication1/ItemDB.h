#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "Item.h"
#include <hash_map>
#include <vector>

extern ItemDB itemDB;

class ItemDB
{
public:

	//************************* Item List *************************
	//iType;  0 : NONE, 1 : ����, 2 : ����, 3 : ����, 4: ����, 5 : �尩, 6 : �Ź�
	//iRarity;  0 : NONE, 1 : �Ϲ�, 2 : ����, 3 : ���, 4 : ����, 5 : ����ũ
	//�Ű����� (�̸�, ����, ��͵�, �δ�, �ƴ�, ���, ��, ��, ��, �ִ� ü��, �ִ� ����)

	Item None = { "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	//����
	Item LongSword			 { "�� �ҵ�", 1, 1, 5, 10, 0, 0, 0, 0, 0, 0, 1, 50 };
	Item Pickaxe			 { "���", 1, 2, 10, 25, 0, 0, 0, 0, 0, 0, 2, 300 };
	Item BFSword			 { "BF���", 1, 3, 20, 40, 0, 0, 0, 0, 0, 0, 3, 750 };
	Item InfinityEdge		 { "������ ���", 1, 4, 100, 200, 10, 0, 0, 0, 0, 0, 4, 2250 };
	Item DawnBlade			 { "����縣�� Ȳȥ��", 1, 5, 150, 300, 0, 0, 0, 0, 0, 0, 5, 6150 };

	//����
	Item WoodenHelm			 { "���� ����", 2, 1, 0, 0, 5, 0, 0, 0, 0, 0, 6, 45 };
	Item IronHelm			 { "ö ����", 2, 2, 0, 0, 10, 0, 0, 0, 100, 50, 7, 280 };
	Item SilverHelm			 { "�� ����", 2, 3, 0, 0, 25, 0, 0, 0, 600, 400, 8, 700 };
	Item GoldHelm			 { "Ȳ�� ����", 2, 4, 0, 0, 50, 0, 0, 0, 1000, 500, 9, 2000 };
	Item Tiara				 { "Ƽ�ƶ�", 2, 5, 0, 0, 100, 0, 0, 0, 2500, 1000, 10, 5500 };

	//����
	Item ClothArmour		 { "õ ����", 3, 1, 0, 0, 15, 0, 0, 0, 300, 100, 11, 55 };
	Item LeatherArmour		 { "���� ����", 3, 2, 0, 0, 50, 0, 0, 0, 500, 300, 12, 325 };
	Item Maille				 { "�罽 ����", 3, 3, 0, 0, 70, 0, 0, 0, 1000, 500, 13, 825 };
	Item PlateArmour		 { "�Ǳ� ����", 3, 4, 0, 0, 100, 0, 0, 0, 2000, 500, 14, 2440 };
	Item MagePlate			 { "������ �÷���Ʈ", 3, 5, 0, 0, 300, 0, 0, 0, 5000, 1000, 15, 6725 };

	//����
	Item WoodenShield		 { "���� ����", 4, 1, 0, 0, 10, 0, 0, 0, 0, 0, 16, 30 };
	Item IronShield			 { "ö ����", 4, 2, 0, 0, 30, 0, 0, 0, 200, 100, 17, 220 };
	Item ShieldofPurification { "��ȭ�� ����", 4, 3, 0, 0, 50, 0, 0, 0, 600, 300, 18, 625 };
	Item GoddessShield		 { "������ ����", 4, 4, 0, 0, 100, 0, 0, 0, 1000, 500, 19, 1900 };
	Item DragonShield		 { "���� ����", 4, 5, 0, 0, 300, 0, 0, 0, 3000, 1000, 20, 5000 };

	//�尩
	Item Vambrace;
	Item Gauntlet;
	Item LeatherGlove;
	Item GoldenGlove;
	Item LightGauntlet;

	//�Ź�
	Item BattleBoots;

	//************************* hash_map *************************

	hash_map<int, Item> Item_Hash
	{
		make_pair(None.iCode, None),
		make_pair(LongSword.iCode, LongSword),
		make_pair(Pickaxe.iCode, Pickaxe),
		make_pair(BFSword.iCode, BFSword),
		make_pair(InfinityEdge.iCode, InfinityEdge),
		make_pair(DawnBlade.iCode, DawnBlade),

		make_pair(WoodenHelm.iCode, WoodenHelm),
		make_pair(IronHelm.iCode, IronHelm),
		make_pair(SilverHelm.iCode, SilverHelm),
		make_pair(GoldHelm.iCode, GoldHelm),
		make_pair(Tiara.iCode, Tiara),

		make_pair(ClothArmour.iCode, ClothArmour),
		make_pair(LeatherArmour.iCode, LeatherArmour),
		make_pair(Maille.iCode, Maille),
		make_pair(PlateArmour.iCode, PlateArmour),
		make_pair(MagePlate.iCode, MagePlate),

		make_pair(WoodenShield.iCode, WoodenShield),
		make_pair(IronShield.iCode, IronShield),
		make_pair(ShieldofPurification.iCode, ShieldofPurification),
		make_pair(GoddessShield.iCode, GoddessShield),
		make_pair(DragonShield.iCode, DragonShield)
	};

	//************************* Item List 2D sort by rarity [rarity][index] *************************

	vector<vector<Item>>	ItemList2D  
	{
	{ None },
	{ LongSword, WoodenShield, ClothArmour, WoodenHelm },			//�Ϲ� ���
	{ Pickaxe, IronHelm, LeatherArmour, IronShield },				//���� ���
	{ BFSword, SilverHelm, Maille, ShieldofPurification },			//��� ���
	{ InfinityEdge, GoldHelm, PlateArmour, GoddessShield },			//���� ���
	{ DawnBlade, Tiara, MagePlate, DragonShield }					//����ũ ���
	};

public:
	Item GetItem(int code) {
		hash_map<int, Item>::iterator itr =itemDB.Item_Hash.find(code);
		Item item = itr->second;
		return item;
	}
};

