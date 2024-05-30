#pragma once

#include <iostream>
#include <string>

using namespace std;

// 무기 클래스
class weapon {
public:
    weapon() {}

    string name;
    int power;
    int availAttack;

    virtual void attack() = 0; // 순수 가상 함수로 정의하여 상속받는 클래스에서 구현하도록 함
};

// 칼 클래스 (무기 클래스를 상속받음)
class Sword : public weapon {
public:
    Sword() {
        name = "Sword";
        power = 5;
        availAttack = 3;
    }

    void attack() override {
 
        cout << "찌르기 !" << endl;
        availAttack--;
    }
};

// 총 클래스 (무기 클래스를 상속받음)
class Gun : public weapon {
public:
    Gun() {
        name = "Gun";
        power = 10;
        availAttack = 1;
    }

    void attack() override {

        cout << "총쏘기 ~" << endl;
        availAttack--;
    }
};
