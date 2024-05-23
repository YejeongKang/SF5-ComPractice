#include <iostream>
#include <string>

using namespace std;

int main() {
	int num, cnum;
	int cnt = 1;

	// 누군가가 31을 부를 때까지 게임이 계속되도록
	while (1) {

		num = 0;

		// 사용자 차례
		while (num < 1 || num > 3){
			cout << "개수를 입력하시오 (종료: -1) : ";
			cin >> num;

			// 1-3 개의 숫자만 말할 수 있음.
			if (num != -1 && num < 1 || num > 3) {
				cout << "1-3 사이의 수를 입력하세요." << endl;
				
			} else if (num == -1) {

				return 0;
			}
		}
		

		cout << "사용자가 부른 숫자!" << endl;

		for (int i = 0; i < num; i++) {

			cout << cnt << endl;

			if (cnt >= 31) {

				cout << "게임 종료! 컴퓨터 승리" << endl;
					
				return 0;
			}
			else {
				cnt++;
			}
		}
		

		// 컴퓨터 차례
		cout << "컴퓨터가 부른 숫자!" << endl;

		cnum = rand() % 3 + 1;

		for (int i = 0; i < cnum; i++) {

			cout << cnt << endl;

			if (cnt >= 31) {

				cout << "게임 종료! 사용자 승리" << endl;
				
				return 0;
			}
			else {
				 cnt++;
			}
		}
	}
}
