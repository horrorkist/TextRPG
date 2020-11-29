#pragma once
#include "Item.h"
#include <hash_map>
#include <vector>

class ItemDB
{
public:

	//************************* Item List *************************
	//iType;  0 : NONE, 1 : 무기, 2 : 투구, 3 : 갑옷, 4: 방패, 5 : 장갑, 6 : 신발
	//iRarity;  0 : NONE, 1 : 일반, 2 : 마법, 3 : 희귀, 4 : 레어, 5 : 유니크
	//매개변수 (이름, 종류, 희귀도, 민댐, 맥댐, 방어, 힘, 민, 지, 최대 체력, 최대 마력)

	Item None = { "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	//무기
	Item LongSword			 { "롱 소드", 1, 1, 5, 10, 0, 0, 0, 0, 0, 0 };
	Item Pickaxe			 { "곡괭이", 1, 2, 10, 25, 0, 0, 0, 0, 0, 0 };
	Item BFSword			 { "BF대검", 1, 3, 20, 40, 0, 0, 0, 0, 0, 0 };
	Item InfinityEdge		 { "무한의 대검", 1, 4, 100, 200, 10, 0, 0, 0, 0, 0 };
	Item DawnBlade			 { "드락사르의 황혼검", 1, 5, 150, 300, 0, 0, 0, 0, 0, 0 };

	//투구
	Item WoodenHelm			 { "나무 투구", 2, 1, 0, 0, 5, 0, 0, 0, 0, 0 };
	Item IronHelm			 { "철 투구", 2, 2, 0, 0, 10, 0, 0, 0, 100, 50 };
	Item SilverHelm			 { "은 투구", 2, 3, 0, 0, 25, 0, 0, 0, 600, 400 };
	Item GoldHelm			 { "황금 투구", 2, 4, 0, 0, 50, 0, 0, 0, 1000, 500 };
	Item Tiara				 { "티아라", 2, 5, 0, 0, 100, 0, 0, 0, 2500, 1000 };

	//갑옷
	Item ClothArmour		 { "천 갑옷", 3, 1, 0, 0, 15, 0, 0, 0, 300, 100 };
	Item LeatherArmour		 { "가죽 갑옷", 3, 2, 0, 0, 50, 0, 0, 0, 500, 300 };
	Item Maille				 { "사슬 갑옷", 3, 3, 0, 0, 70, 0, 0, 0, 1000, 500 };
	Item PlateArmour		 { "판금 갑옷", 3, 4, 0, 0, 100, 0, 0, 0, 2000, 500 };
	Item MagePlate			 { "메이지 플레이트", 3, 5, 0, 0, 300, 0, 0, 0, 5000, 1000 };

	//방패
	Item WoodenShield		 { "나무 방패", 4, 1, 0, 0, 10, 0, 0, 0, 0, 0 };
	Item IronShield			 { "철 방패", 4, 2, 0, 0, 30, 0, 0, 0, 200, 100 };
	Item ShildofPurification { "정화의 방패", 4, 3, 0, 0, 50, 0, 0, 0, 600, 300 };
	Item GoddessShield		 { "여신의 방패", 4, 4, 0, 0, 100, 0, 0, 0, 1000, 500 };
	Item DragonShield		 { "용의 방패", 4, 5, 0, 0, 300, 0, 0, 0, 3000, 1000 };

	//장갑
	Item Vambrace;
	Item Gauntlet;
	Item LeatherGlove;
	Item GoldenGlove;
	Item LightGauntlet;

	//신발
	Item BattleBoots;

	//************************* Item List 2D sort by rarity [rarity][index] *************************

	vector<vector<Item>>	ItemList2D  
	{
	{None},
	{ LongSword, WoodenShield, ClothArmour, WoodenHelm },			//일반 등급
	{ Pickaxe, IronHelm, LeatherArmour, IronShield },				//마법 등급
	{ BFSword, SilverHelm, Maille, ShildofPurification },			//희귀 등급
	{ InfinityEdge, GoldHelm, PlateArmour, GoddessShield },			//레어 등급
	{ DawnBlade, Tiara, MagePlate, DragonShield }					//유니크 등급
	};
};

