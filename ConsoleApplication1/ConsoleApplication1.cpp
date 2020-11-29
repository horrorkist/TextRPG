#include "SystemManager.h"
#include "BattleManager.h"
#include "StoreManager.h"
#include "Character.h"
#include "MonsterDB.h"
#include "ItemDB.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

<<<<<<< HEAD
SystemManager systemManager;
BattleManager battleManager;

ifstream inputStream;
ofstream outputStream;


//************************* Monster List *************************
//(이름, 맥댐, 민댐, 방어, 골드, 경험치, 체력)

Monster Mouse("생쥐", 5, 1, 0, 10, 5, 30);
Monster Spider("거미", 7, 3, 0, 14, 7, 40);
Monster Bet("박쥐", 15, 8, 0, 15, 10, 25);
Monster Bandit("산적", 30, 20, 3, 70, 40, 80);
Monster Snake("뱀", 10, 5, 0, 40, 15, 40);

Monster Wolf("늑대", 30, 15, 0, 75, 45, 150);
Monster Bear("갈색 곰", 40, 20, 0, 100, 50, 200);
Monster Wildboar("멧돼지", 25, 10, 0, 60, 30, 100);

//Monster Wisp;
//Monster Kobold;
//Monster Skeleton;
Monster Goblin("고블린", 60, 40, 3, 200, 80, 250);
Monster Orc("오크", 120, 80, 5, 350, 100, 400);
Monster Ogre("오우거", 150, 100, 10, 500, 150, 1000);

Monster Dragon("오닉시아", 1000, 700, 50, 20000, 5000, 10000);
Monster Hatchling("새끼 용", 300, 200, 30, 2500, 300, 500);
Monster Slime("슬라임", 15, 5, 1, 30, 10, 100);



//************************* Item List *************************
//iType;  0 : NONE, 1 : 무기, 2 : 투구, 3 : 갑옷, 4: 방패, 5 : 장갑, 6 : 신발
//iRarity;  0 : NONE, 1 : 일반, 2 : 마법, 3 : 희귀, 4 : 레어, 5 : 유니크
//Item(string name, int type, int rarity, int minAtt, int maxAtt, int def, int str, int dex, int intel, int maxHp, int maxMp)
//매개변수 (이름, 종류, 희귀도, 민댐, 맥댐, 방어, 힘, 민, 지, 최대 체력, 최대 마력)

Item None("", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

//무기
Item LongSword("롱 소드", 1, 1, 5, 10, 0, 0, 0, 0, 0, 0);
Item Pickaxe("곡괭이", 1, 2, 10, 25, 0, 0, 0, 0, 0, 0);
Item BFSword("BF대검", 1, 3, 20, 40, 0, 0, 0, 0, 0, 0);
Item InfinityEdge("무한의 대검", 1, 4, 100, 200, 10, 0, 0, 0, 0, 0);
Item DawnBlade("드락사르의 황혼검", 1, 5, 150, 300, 0, 0, 0, 0, 0, 0);

//투구
Item WoodenHelm("나무 투구", 2, 1, 0, 0, 5, 0, 0, 0, 0, 0);
Item IronHelm("철 투구", 2, 2, 0, 0, 10, 0, 0, 0, 100, 50);
Item SilverHelm("은 투구", 2, 3, 0, 0, 25, 0, 0, 0, 600, 400);
Item GoldHelm("황금 투구", 2, 4, 0, 0, 50, 0, 0, 0, 1000, 500);
Item Tiara("티아라", 2, 5, 0, 0, 100, 0, 0, 0, 2500, 1000);

//갑옷
Item ClothArmour("천 갑옷", 3, 1, 0, 0, 15, 0, 0, 0, 300, 100);
Item LeatherArmour("가죽 갑옷", 3, 2, 0, 0, 50, 0, 0, 0, 500, 300);
Item Maille("사슬 갑옷", 3, 3, 0, 0, 70, 0, 0, 0, 1000, 500);
Item PlateArmour("판금 갑옷", 3, 4, 0, 0, 100, 0, 0, 0, 2000, 500);
Item MagePlate("메이지 플레이트", 3, 5, 0, 0, 300, 0, 0, 0, 5000, 1000);

//방패
Item WoodenShield("나무 방패", 4, 1, 0, 0, 10, 0, 0, 0, 0, 0);
Item IronShield("철 방패", 4, 2, 0, 0, 30, 0, 0, 0, 200, 100);
Item ShildofPurification("정화의 방패", 4, 3, 0, 0, 50, 0, 0, 0, 600, 300);
Item GoddessShield("여신의 방패", 3, 4, 0, 0, 100, 0, 0, 0, 1000, 500);
Item DragonShield("용의 방패", 4, 5, 0, 0, 300, 0, 0, 0, 3000, 1000);

//장갑
Item Vambrace;
Item Gauntlet;
Item LeatherGlove;
Item GoldenGlove;
Item LightGauntlet;

//신발
Item BattleBoots;

//************************* Battle Field List *************************
vector<vector<Monster>> BattleFields = { {Mouse, Spider, Bet, Snake, Bandit}, {Wolf, Bear, Wildboar}, {Goblin, Orc, Ogre}, {Hatchling, Dragon} };


=======
>>>>>>> Item
//************************* Player *************************
Character cPlayer;

//************************* DB *************************
ItemDB itemDB;
MonsterDB monsterDB;

//************************* Manager *************************
SystemManager	 systemManager;
BattleManager	 battleManager;
StoreManager	 storeManager;
int main()
{
	inputStream.open("data.txt");
	if (inputStream.is_open()) {
		string str;
		getline(inputStream, str);
		cPlayer.SetUsingData(str);
		inputStream.close();
	}
	else
		cPlayer.CreateNewChar();
	systemManager.ShowMainMenu();


	return 0;
}


