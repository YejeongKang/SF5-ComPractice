#include "character.h"


#include <vector>
//- 필드: 'hp, level, 무기들'
//- 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만 사용해서 공격할 수 있 으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)

void character::printInfo() {
    cout << "이름 : " << name << endl;
    cout << "체력 : " << hp << endl;
    cout << "레벨 : " << level << endl;

}
void character::printMyWeapons() {
    cout << "[현재 보유한 무기] \n";
    for (weapon* w : weapons) {
        cout << w->name << " ";
    }
	cout << endl;

}

void character::farmingWeapon(Field f) {
	string weap;

	while (1) {
		std::cout << "필드로 나왔습니다. 어떤 무기를 주울까요?" << endl;
		f.printField();
		cin >> weap;

		if (weap == "Gun") {
			// 플레이어의 무기고에 저장
			weapon* w = new Gun();
			weapons.push_back(w);
			std::cout << name << "이(가) 무기 " << w->name << "을(를) 주웠습니다." << endl;

			// 필드의 무기 목록에서 제거
			f.delWeapon(weap);

		}
		else if (weap == "Sword") {

			// 플레이어의 무기고에 저장
			weapon* w = new Sword();
			weapons.push_back(w);
			std::cout << name << "이(가) 무기 " << w->name << "을(를) 주웠습니다." << endl;

			// 필드의 무기 목록에서 제거
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
		// 현재 보유한 무기 출력
		if (weapons.size() == 0) {
			cout << "보유한 무기가 없습니다. 먼저 무기를 주워주세요." << endl;
			break;
		}
		else {
			printMyWeapons();

			cout << "공격할 무기와 적의 이름을 공백을 두고 입력하시오. (ex: Gun 강예정)" << endl;
			cin >> weap >> target;

			// 무기 구분 후 w에 입력
			for (int i = 0; i < weapons.size(); i++) {
				if (weapons[i]->name == weap) {
					widx = i;
					break;
				}
			}

			// 적이 존재하는지
			for (int i = 0; i < players.size(); i++) {
				if (players[i].name == target) {
					eidx = i;
					targetFlag = true;
					break;
				}
			}

			// 적이 존재한다면
			if (targetFlag) {
				if (weapons[widx]->availAttack > 0) {
					weapons[widx]->attack();
					players[eidx].hp -= weapons[widx]->power;
					cout << players[eidx].name << "의 HP가 " << weapons[widx]->power << "만큼 감소하여 현재 HP: " << players[eidx].hp << endl;
					if (players[eidx].hp <= 0) {
						cout << players[eidx].name << "이(가) 쓰러졌습니다." << endl;
					}
				}
				else {
					cout << weapons[widx]->power << " 공격은 더 이상 사용할 수 없습니다." << endl;
				}
			}
			else {
				cout << "적을 찾을 수 없습니다." << endl;
				continue;
			}
		}
	}
	
    
}



