#include "Item.h"


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