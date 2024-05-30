#pragma once

#include <vector>
#include <string>
#include "Weapon.h"
#include "Field.h"

using namespace std;

class character {
public:
    int hp;
    int level;
    string name;
    vector<weapon*> weapons;

    character(string n, int h, int l) : name(n), hp(h), level(l) {}

    void printInfo();

    void printMyWeapons();

    void farmingWeapon(Field f);

    void attack(vector<character> players);
    
};
