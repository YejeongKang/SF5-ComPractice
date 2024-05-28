#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RAND 6

int main(){
	vector <int> lotto;
	vector <int> vec;
	int cnum, num;
	int i = 1;
	int cnt = 0;
	bool dup ;

	lotto.reserve(RAND);
	vec.reserve(RAND);

	// 컴퓨터가 지정한 랜덤 숫자 6개 lotto에 넣기
	while (lotto.size() < RAND) {
		
		cnum = rand() % 25 + 1;

		for (int l : lotto) {
			if (cnum == l) continue;
		} 
		lotto.push_back(cnum);
	}
	
	// 사용자 입력받기 
	cout << "숫자는 1- 25 까지의 숫자만 입력할 수 있습니다." << endl;

	while (vec.size() < RAND) {
		
		dup = false;

		cout << endl << i << "번째 번호를 입력하세요 : ";
		
		cin >> num;
		
		if (num == -1) return 0;

		if (num < 1 or 25 < num) {
			
			cout << "1 - 25 까지의 숫자만 입력하세요. " << endl;

			continue;
		}
		else {

			for (int v : vec) {
				if (num == v) {

					cout << endl << "중복된 숫자입니다. " << endl;

					dup = true;
				}
			}
			if (dup == true) {
				continue;
			}
			else {
				vec.push_back(num);

				i++;
			}
		}
	}

	// 두 벡터 비교
	for (int i = 0; i < RAND; i++) {
		for (int j = 0; j < RAND; j++) {
			if (lotto[i] == vec[j]) cnt++;
		}
	}

	cout << endl << "----------------------------\n당첨번호 공개!" << endl;

	for (int l : lotto)	cout << l << " ";
	
	cout << endl << "1 - 7 등까지 결과가 나올 수 있습니다.\n결과 : " << 7 - cnt << "등입니다!";
	
}

