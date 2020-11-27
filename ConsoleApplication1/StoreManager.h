#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Item.h"


using namespace std;


class StoreManager
{
private:

	int storelevel; //상점 레벨
	vector<string> sBattleField = { "상점 아이템 1", "상점 아이템 2", "상점 아이템 3" }; //랜덤한 아이템 

public:

	void StoreMenu() const;
};

