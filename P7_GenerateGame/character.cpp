#include "character.h"


#include <vector>
//- �ʵ�: 'hp, level, �����'
//- �޼ҵ� : ���� �ݱ�, �����ϱ�(�����ϱ� �޼ҵ忡���� ������ �ִ� ����鸸 ����ؼ� ������ �� �� ����, ���ݴ��� ĳ������ hp�� �ش��ϴ� ������ ���ݷ¸�ŭ �����Ѵ�.)

void character::printInfo() {
    cout << "�̸� : " << name << endl;
    cout << "ü�� : " << hp << endl;
    cout << "���� : " << level << endl;

}
void character::printMyWeapons() {
    cout << "[���� ������ ����] \n";
    for (weapon* w : weapons) {
        cout << w->name << " ";
    }
	cout << endl;

}

void character::farmingWeapon(Field f) {
	string weap;

	while (1) {
		std::cout << "�ʵ�� ���Խ��ϴ�. � ���⸦ �ֿ���?" << endl;
		f.printField();
		cin >> weap;

		if (weap == "Gun") {
			// �÷��̾��� ����� ����
			weapon* w = new Gun();
			weapons.push_back(w);
			std::cout << name << "��(��) ���� " << w->name << "��(��) �ֿ����ϴ�." << endl;

			// �ʵ��� ���� ��Ͽ��� ����
			f.delWeapon(weap);

		}
		else if (weap == "Sword") {

			// �÷��̾��� ����� ����
			weapon* w = new Sword();
			weapons.push_back(w);
			std::cout << name << "��(��) ���� " << w->name << "��(��) �ֿ����ϴ�." << endl;

			// �ʵ��� ���� ��Ͽ��� ����
			f.delWeapon(weap);
		}
		else {
			continue;
		}
		break;
	}
   
}

void character::attack(vector<character> players) {
	int widx, eidx;
	string weap, target;
	bool targetFlag = false;
	
	while (1) {
		// ���� ������ ���� ���
		if (weapons.size() == 0) {
			cout << "������ ���Ⱑ �����ϴ�. ���� ���⸦ �ֿ��ּ���." << endl;
			break;
		}
		else {
			printMyWeapons();

			cout << "������ ����� ���� �̸��� ������ �ΰ� �Է��Ͻÿ�. (ex: Gun ������)" << endl;
			cin >> weap >> target;

			// ���� ���� �� w�� �Է�
			for (int i = 0; i < weapons.size(); i++) {
				if (weapons[i]->name == weap) {
					widx = i;
					break;
				}
			}

			// ���� �����ϴ���
			for (int i = 0; i < players.size(); i++) {
				if (players[i].name == target) {
					eidx = i;
					targetFlag = true;
					break;
				}
			}

			// ���� �����Ѵٸ�
			if (targetFlag) {
				if (weapons[widx]->availAttack > 0) {
					weapons[widx]->attack();
					players[eidx].hp -= weapons[widx]->power;
					cout << players[eidx].name << "�� HP�� " << weapons[widx]->power << "��ŭ �����Ͽ� ���� HP: " << players[eidx].hp << endl;
					if (players[eidx].hp <= 0) {
						cout << players[eidx].name << "��(��) ���������ϴ�." << endl;
					}
				}
				else {
					cout << weapons[widx]->power << " ������ �� �̻� ����� �� �����ϴ�." << endl;
				}
			}
			else {
				cout << "���� ã�� �� �����ϴ�." << endl;
				continue;
			}
		}
	}
	
    
}



