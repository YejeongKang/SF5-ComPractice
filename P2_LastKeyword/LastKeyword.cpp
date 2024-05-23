#include <vector>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

#define TL 10

int main() {
	int cnt = 0;
	double timeTaken = 0;
	vector<string> w_vec = {"base"};
	string word;
	bool flag;

	clock_t startTime = clock();

	while (timeTaken <= TL) {
		// 중복 깃발 초기화
		flag = false;		

		// 현재까지 말한 단어 모두 출력
		for (string w : w_vec) cout << w;

		// 새로운 단어 입력
		cout << endl << "다음 단어를 입력하세요 (종료: -1): ";

		cin >> word;

		cout << endl;

		// 입력 받은 직후 시간 체크
		clock_t endTime = clock();

		timeTaken = (endTime - startTime) / CLOCKS_PER_SEC;

		if (word == "-1") {

			return 0;
		}

		// 중복 확인
		for (string w : w_vec) {
			if (word == w) {

				flag = true;

				break;
			}
		}

		// 중복임을 알려주고 새로운 입력 받기
		if (flag == true) {

			cout << "중복된 단어입니다." << endl << endl;
		}
		else {

			// 정답 확인
			if (word[0] == (w_vec.back()).back()) {

				w_vec.push_back(" -> ");
				w_vec.push_back(word);
			}
			else {
				// 오답임을 알려주고 새로운 입력 받기
				cout << "오답입니다." << endl << endl;
			}
		}
	}
	cout << "시간이 초과되었습니다!" << endl;
	
	// 현재까지 말한 단어 모두 출력
	for (string w : w_vec) cout << w;

	cout << endl << "입력한 단어의 개수는 : " << ((w_vec.size()-1)/2 + 1);
}
