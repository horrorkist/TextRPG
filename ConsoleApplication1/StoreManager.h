#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include "Item.h"


using namespace std;


class StoreManager
{
private:

	int storelevel; //���� ����
	vector<string> sBattleField = { "���� ������ 1", "���� ������ 2", "���� ������ 3" }; //������ ������ 

public:

	void StoreMenu() const;
};

