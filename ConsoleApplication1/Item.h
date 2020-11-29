#pragma once

#include <string>

class Character;

using namespace std;

class Item {
private:

	string		strName;

	int			iType; // 0 : NONE, 1 : ����, 2 : ����, 3 : ����, 4: ����, 5 : �尩, 6 : �Ź�
	int			iRarity; // 0 : NONE, 1 : �Ϲ�, 2 : ����, 4 : ���, 5 : ����, 6 : ����ũ

	int			iItemMaxAtt;
	int			iItemMinAtt;
	int			iItemDef;
	int			iItemStr;
	int			iItemDex;
	int			iItemInt;
	int			iItemMaxHp;
	int			iItemMaxMp;

	int			iPrice;
	int			iCode;

public:

	Item(void);

	Item(string name, int type, int rarity, int minAtt, int maxAtt, int def, int str, int dex, int intel, int maxHp, int maxMp, int code)
		: strName(name), iType(type), iRarity(rarity), iItemMaxAtt(maxAtt), iItemMinAtt(minAtt), iItemDef(def), iItemStr(str), iItemDex(dex), iItemInt(intel), iItemMaxHp(maxHp), iItemMaxMp(maxMp), iCode(code) {
		iPrice = 0;
	};

	void Equip(Character &player);
	void ItemCompare(Character player);
	void ShowItemInfo() const;
	int GetItemType() const { return iType; }
	int GetItemPrice() const { return iPrice; }
	string GetItemName() const { return strName; }
	int GetItemCode() const { return iCode; }

	friend class ItemDB;
};
