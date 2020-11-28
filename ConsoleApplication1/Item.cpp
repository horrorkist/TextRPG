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

void Item::ShowItemInfo() const {

	if (this->iType == 0) {
		//cout << "**************************************************" << endl;
		cout << "비어있음" << endl;
		cout << "**************************************************" << endl;
	}
	return;

	string strType;
	switch (this->iType) {
	case 1:
		strType = "무기";
		break;
	case 2:
		strType = "투구";
		break;
	case 3:
		strType = "갑옷";
		break;
	case 4:
		strType = "방패";
		break;
	case 5:
		strType = "장갑";
		break;
	case 6:
		strType = "신발";
		break;
	default:
		break;
	}
	cout << "**************************************************" << endl;
	cout << "      『" << this->strName << "』" << endl;
	cout << "타입 : " << strType << endl;
	if (iType == 1) cout << "공격력 : " << this->iItemMinAtt << " - " << this->iItemMaxAtt << endl;
	else {
		cout << "방어력 : " << this->iItemDef << endl;
		cout << "추가 체력 : " << this->iItemMaxHp << endl;
		cout << "추가 마력: " << this->iItemMaxMp << endl;
	}
	cout << "가격 : " << this->iPrice << "G" << endl;
	cout << "**************************************************" << endl;
	return;
}