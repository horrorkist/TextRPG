#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Item.h"
#include <ctime>

using namespace std;


class StoreManager
{
private:

	int storelevel = 1; //상점 레벨

	Item Slot1;
	Item Slot2;
	Item Slot3;


public:

	void StoreMenu() const;

	void ShowStoreList() const;

};

