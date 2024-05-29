#include "Lotto.h"
#include "User.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RAND 6
#define numLimit 25

int main() {
	vector <int> v_lotto;
	vector <int> vec;

	// 로또 번호 생성
	v_lotto = generateLottoNum(numLimit, RAND);

	// 사용자 입력 받기
	vec = userInput(numLimit, RAND);

	if (vec.size() != RAND) return 0;

	else {
		std::cout << endl << "----------------------------\n당첨번호 공개!" << endl;

		for (int l : v_lotto)	std::cout << l << " ";

		std::cout << endl << "1 - 7 등까지 결과가 나올 수 있습니다.\n결과 : " << CompareVec(v_lotto, vec, RAND) << "등입니다!";
	}
}
