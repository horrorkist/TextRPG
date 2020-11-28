#include "Character.h"

Item::Item(void) {
	strName = "";

	iType = 0; // 0 : NONE, 1 : ����, 2 : ����, 3 : ����, 4: ����, 5 : �尩, 6 : �Ź�
	iRarity = 0; // 0 : NONE, 1 : �Ϲ�, 2 : ����, 4 : ���, 5 : ����, 6 : ����ũ

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

void Item::ItemCompare(Character player) { //���� ���� �����۰� ���Ͽ� �����ִ� �Լ�

}

void Item::ShowItemInfo() const {

	if (this->iType == 0) {
		//cout << "**************************************************" << endl;
		cout << "�������" << endl;
		cout << "**************************************************" << endl;
	}
	return;

	string strType;
	switch (this->iType) {
	case 1:
		strType = "����";
		break;
	case 2:
		strType = "����";
		break;
	case 3:
		strType = "����";
		break;
	case 4:
		strType = "����";
		break;
	case 5:
		strType = "�尩";
		break;
	case 6:
		strType = "�Ź�";
		break;
	default:
		break;
	}
	cout << "**************************************************" << endl;
	cout << "      ��" << this->strName << "��" << endl;
	cout << "Ÿ�� : " << strType << endl;
	if (iType == 1) cout << "���ݷ� : " << this->iItemMinAtt << " - " << this->iItemMaxAtt << endl;
	else {
		cout << "���� : " << this->iItemDef << endl;
		cout << "�߰� ü�� : " << this->iItemMaxHp << endl;
		cout << "�߰� ����: " << this->iItemMaxMp << endl;
	}
	cout << "���� : " << this->iPrice << "G" << endl;
	cout << "**************************************************" << endl;
	return;
}