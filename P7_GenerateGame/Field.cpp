#include "Field.h"

void Field::makeField() { // �ʵ忡 �����ϴ� �����(�Ĺ� ���ؼ�)

	int g = rand() % 5 + 3;
	int s = rand() % 5 + 3;

	fieldWeapons.reserve(g + s);

	for (int i = 0; i < g; i++) {
		fieldWeapons.push_back("Gun");
	}

	for (int i = 0; i < s; i++) {
		fieldWeapons.push_back("Sword");
	}

}

void Field::printField() {
	for (string fw : fieldWeapons) {
		cout << fw << " ";
	}
	cout << endl;
}

void Field::delWeapon(string w) {
	for (int i = 0; i < fieldWeapons.size(); i++) {

		if (fieldWeapons[i] == w) {

			fieldWeapons.erase(fieldWeapons.begin() + i);
		}
	}
}