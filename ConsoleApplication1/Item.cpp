#include "Character.h"

Item::Item(void) {
	strName = "";

	iType = 0; // 0 : NONE, 1 : 무기, 2 : 투구, 3 : 갑옷, 4: 방패, 5 : 장갑, 6 : 신발
	iRarity = 0; // 0 : NONE, 1 : 일반, 2 : 마법, 4 : 희귀, 5 : 레어, 6 : 유니크

	this->iItemMaxAtt = 0;
	this->iItemMinAtt = 0;
	this->iItemDef = 0;
	this->iItemStr = 0;
	this->iItemDex = 0;
	this->iItemInt = 0;
	this->iItemMaxHp = 0;
	this->iItemMaxMp = 0;
}

void Item::Equip(Character player) {

	player.iMaxAtt -= player.Equipment[this->iType].iItemMaxAtt;
	player.iMinAtt -= player.Equipment[this->iType].iItemMinAtt;
	player.iStr -= player.Equipment[this->iType].iItemStr;
	player.iDex -= player.Equipment[this->iType].iItemDex;
	player.iInt -= player.Equipment[this->iType].iItemInt;
	player.iMaxHp -= player.Equipment[this->iType].iItemMaxHp;
	player.iMaxMp -= player.Equipment[this->iType].iItemMaxMp;
	player.iDef -= player.Equipment[this->iType].iItemDef;

	player.Equipment[this->iType] = *this;

	player.iMaxAtt += player.Equipment[this->iType].iItemMaxAtt;
	player.iMinAtt += player.Equipment[this->iType].iItemMinAtt;
	player.iStr += player.Equipment[this->iType].iItemStr;
	player.iDex += player.Equipment[this->iType].iItemDex;
	player.iInt += player.Equipment[this->iType].iItemInt;
	player.iMaxHp += player.Equipment[this->iType].iItemMaxHp;
	player.iMaxMp += player.Equipment[this->iType].iItemMaxMp;
	player.iDef += player.Equipment[this->iType].iItemDef;
}

void Item::ItemCompare(Character player) { //착용 중인 아이템과 비교하여 보여주는 함수

}