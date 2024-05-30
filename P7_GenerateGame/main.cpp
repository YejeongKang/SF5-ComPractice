//프로젝트 7. 클래스 종합 - 게임 만들기
//1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
//
// 2. 캐릭터 클래스
//- 필드: 'hp, level, 무기들'
//- 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만 사용해서 공격할 수 있 으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)
//
// 3. 무기 클래스
//- 필드 : 공격력, 공격 가능 횟수
//- 메소드 : 공격하기
// 
// 4. 총 & 칼 클래스(무기 클래스를 상속 받는 클래스)
//- 칼 : 공격력 - 5, 공격가능횟수 - 3, 공격하기 - "찌르기" 출력
//- 총 : 공격력 - 10, 공격가능횟수 - 1, 공격하기 - "총쏘기" 출력
//5. 파일 분리하기

#include "character.h"
#include "weapon.h"
#include "Field.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum User
{
	GET_WEAPON = 1,
	ATTACK,
	LOGOUT
};

int main()
{
	int idx, manipulating;
	string input, weap, target;
	bool exist = false;
	vector<character> players;

	// 필드에 존재할 무기들을 최초 한 번 생성
	Field field;

	field.makeField();

	while (1) {
		cout << "접속할 캐릭터의 닉네임을 입력하시오. (종료 : -1) \n:";
		cin >> input;

		if (input == "-1") { // 종료를 원한다면
			return 0;
		}
		else {
			// 계정 체크
			for (int i = 0; i < players.size(); i++) {
				if (input == players[i].name) {
					exist = true;
					// switch 문에서 접근하기 위해 인덱스 기록
					idx = i;
				}
			}
			if (exist) {// 이미 등록된 계정이라면
				// 계정 정보 출력
				players[idx].printInfo();
			}
			else {// 신규 등록이 필요하다면
				character NA(input, 100, 1);

				cout << "계정 생성!" << endl;

				// 값 비교를 하기 위해 벡터에 인스턴스 추가.
				players.push_back(NA);

				// 벡터의 마지막에 넣었기 때문에.
				// switch 문에서 접근하기 위해 인덱스 기록
				idx = players.size() - 1;
			}
		}
		while (1) {
			cout << "원하는 조작을 입력하세요. \n1) 필드에서 무기 줍기 \n2) 공격하기 \n3) 로그아웃 " << endl;
			cin >> manipulating;

			switch (manipulating) {
			case User::GET_WEAPON:
				players[idx].farmingWeapon(field);
				continue;
				break;

			case User::ATTACK:
				players[idx].attack(players);
				continue;
				break;

			case User::LOGOUT:
				break;

			default:
				cout << "동작을 다시 입력하세요." << endl;
				continue;
			}
			cout << "실행 완료!" << endl;
			break;
		} 
	}
	return 0;
}
