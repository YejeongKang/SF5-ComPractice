#include "User.h"

using namespace std;

vector <int> userInput(int n1, int n2) {
	int num;
	int i = 1;
	bool dup;
	vector <int> vec;

	vec.reserve(n2);

	// 사용자 입력받기 
	std::cout << "숫자는 1 - " << n1 << " 까지의 숫자만 입력할 수 있습니다." << endl;

	while (vec.size() < n2) {

		dup = false;

		std::cout << endl << i << "번째 번호를 입력하세요 : ";

		cin >> num;

		if (num == -1) return vec;

		if (num < 1 or 25 < num) {

			std::cout << "1 - " << n1 << " 까지의 숫자만 입력하세요." << endl;

			continue;
		}
		else {

			for (int v : vec) {
				if (num == v) {

					std::cout << endl << "중복된 숫자입니다. " << endl;

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
	return vec;
}