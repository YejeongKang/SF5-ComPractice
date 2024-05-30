#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Field {
public:
	Field(){}

	vector<string> fieldWeapons;

	void makeField();
	void printField();
	void delWeapon(string w);

};
