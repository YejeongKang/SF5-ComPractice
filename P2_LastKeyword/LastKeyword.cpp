#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
	int cnt = 0;
	vector<string> w_vec = {"base"};
	string word;
	bool flag = false;

	while (1) {
		// 현재까지 말한 단어 모두 출력
		for (string w : w_vec) cout << w;

		// 새로운 단어 입력
		cout << endl << "다음 단어를 입력하세요 : " << endl;

		cin >> word;

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

			continue;
		}
		else {

			if (word[0] == (w_vec.back()).back()) {

				w_vec.push_back(" -> ");
				w_vec.push_back(word);
			}
			else {
				// 오답임을 알려주고 새로운 입력 받기
				cout << "잘못된 입력입니다." << endl << endl;

				continue;
			}
		}
	}
}