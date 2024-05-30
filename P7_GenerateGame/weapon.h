#pragma once

#include <iostream>
#include <string>

using namespace std;

// ���� Ŭ����
class weapon {
public:
    weapon() {}

    string name;
    int power;
    int availAttack;

    virtual void attack() = 0; // ���� ���� �Լ��� �����Ͽ� ��ӹ޴� Ŭ�������� �����ϵ��� ��
};

// Į Ŭ���� (���� Ŭ������ ��ӹ���)
class Sword : public weapon {
public:
    Sword() {
        name = "Sword";
        power = 5;
        availAttack = 3;
    }

    void attack() override {
 
        cout << "��� !" << endl;
        availAttack--;
    }
};

// �� Ŭ���� (���� Ŭ������ ��ӹ���)
class Gun : public weapon {
public:
    Gun() {
        name = "Gun";
        power = 10;
        availAttack = 1;
    }

    void attack() override {

        cout << "�ѽ�� ~" << endl;
        availAttack--;
    }
};
