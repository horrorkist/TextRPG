#pragma once
#include "Item.h"
#include <hash_map>
#include <vector>

class ItemDB
{
public:

	//************************* Item List *************************
	//iType;  0 : NONE, 1 : ����, 2 : ����, 3 : ����, 4: ����, 5 : �尩, 6 : �Ź�
	//iRarity;  0 : NONE, 1 : �Ϲ�, 2 : ����, 3 : ���, 4 : ����, 5 : ����ũ
	//�Ű����� (�̸�, ����, ��͵�, �δ�, �ƴ�, ���, ��, ��, ��, �ִ� ü��, �ִ� ����)

	Item None = { "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//����
	Item LongSword			 { "�� �ҵ�", 1, 1, 5, 10, 0, 0, 0, 0, 0, 0 };
	Item Pickaxe			 { "���", 1, 2, 10, 25, 0, 0, 0, 0, 0, 0 };
	Item BFSword			 { "BF���", 1, 3, 20, 40, 0, 0, 0, 0, 0, 0 };
	Item InfinityEdge		 { "������ ���", 1, 4, 100, 200, 10, 0, 0, 0, 0, 0 };
	Item DawnBlade			 { "����縣�� Ȳȥ��", 1, 5, 150, 300, 0, 0, 0, 0, 0, 0 };

	//����
	Item WoodenHelm			 { "���� ����", 2, 1, 0, 0, 5, 0, 0, 0, 0, 0 };
	Item IronHelm			 { "ö ����", 2, 2, 0, 0, 10, 0, 0, 0, 100, 50 };
	Item SilverHelm			 { "�� ����", 2, 3, 0, 0, 25, 0, 0, 0, 600, 400 };
	Item GoldHelm			 { "Ȳ�� ����", 2, 4, 0, 0, 50, 0, 0, 0, 1000, 500 };
	Item Tiara				 { "Ƽ�ƶ�", 2, 5, 0, 0, 100, 0, 0, 0, 2500, 1000 };

	//����
	Item ClothArmour		 { "õ ����", 3, 1, 0, 0, 15, 0, 0, 0, 300, 100 };
	Item LeatherArmour		 { "���� ����", 3, 2, 0, 0, 50, 0, 0, 0, 500, 300 };
	Item Maille				 { "�罽 ����", 3, 3, 0, 0, 70, 0, 0, 0, 1000, 500 };
	Item PlateArmour		 { "�Ǳ� ����", 3, 4, 0, 0, 100, 0, 0, 0, 2000, 500 };
	Item MagePlate			 { "������ �÷���Ʈ", 3, 5, 0, 0, 300, 0, 0, 0, 5000, 1000 };

	//����
	Item WoodenShield		 { "���� ����", 4, 1, 0, 0, 10, 0, 0, 0, 0, 0 };
	Item IronShield			 { "ö ����", 4, 2, 0, 0, 30, 0, 0, 0, 200, 100 };
	Item ShildofPurification { "��ȭ�� ����", 4, 3, 0, 0, 50, 0, 0, 0, 600, 300 };
	Item GoddessShield		 { "������ ����", 4, 4, 0, 0, 100, 0, 0, 0, 1000, 500 };
	Item DragonShield		 { "���� ����", 4, 5, 0, 0, 300, 0, 0, 0, 3000, 1000 };

	//�尩
	Item Vambrace;
	Item Gauntlet;
	Item LeatherGlove;
	Item GoldenGlove;
	Item LightGauntlet;

	//�Ź�
	Item BattleBoots;

	//************************* Item List 2D sort by rarity [rarity][index] *************************

	vector<vector<Item>>	ItemList2D  
	{
	{None},
	{ LongSword, WoodenShield, ClothArmour, WoodenHelm },			//�Ϲ� ���
	{ Pickaxe, IronHelm, LeatherArmour, IronShield },				//���� ���
	{ BFSword, SilverHelm, Maille, ShildofPurification },			//��� ���
	{ InfinityEdge, GoldHelm, PlateArmour, GoddessShield },			//���� ���
	{ DawnBlade, Tiara, MagePlate, DragonShield }					//����ũ ���
	};
};

