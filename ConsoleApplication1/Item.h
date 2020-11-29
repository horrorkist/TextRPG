#pragma once

#include <string>

class Character;

using namespace std;

class Item {
private:

	string		strName;

	int			iType; // 0 : NONE, 1 : ¹«±â, 2 : Åõ±¸, 3 : °©¿Ê, 4: ¹æÆÐ, 5 : Àå°©, 6 : ½Å¹ß
	int			iRarity; // 0 : NONE, 1 : ÀÏ¹Ý, 2 : ¸¶¹ý, 4 : Èñ±Í, 5 : ·¹¾î, 6 : À¯´ÏÅ©

	int			iItemMaxAtt;
	int			iItemMinAtt;
	int			iItemDef;
	int			iItemStr;
	int			iItemDex;
	int			iItemInt;
	int			iItemMaxHp;
	int			iItemMaxMp;

	int			iPrice;
public:

	Item(void);

	Item(string name, int type, int rarity, int minAtt, int maxAtt, int def, int str, int dex, int intel, int maxHp, int maxMp)
		: strName(name), iType(type), iRarity(rarity), iItemMaxAtt(maxAtt), iItemMinAtt(minAtt), iItemDef(def), iItemStr(str), iItemDex(dex), iItemInt(intel), iItemMaxHp(maxHp), iItemMaxMp(maxMp) {
		iPrice = 0;
	};

	void Equip(Character &player);
	void ItemCompare(Character player);
	void ShowItemInfo() const;
	int GetItemType() const { return iType; }
	int GetItemPrice() const { return iPrice; }
	string GetItemName() const { return strName; }
};
