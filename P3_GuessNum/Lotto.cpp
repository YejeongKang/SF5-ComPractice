#include "Lotto.h"

using namespace std;

vector <int> generateLottoNum(int n1, int n2) {
	vector <int> v_lotto;
	int cnum;

	v_lotto.reserve(n2);

	// 컴퓨터가 지정한 랜덤 숫자 6개 lotto에 넣기
	while (v_lotto.size() < n2) {

		cnum = rand() % n1 + 1;

		for (int l : v_lotto) {
			if (cnum == l) continue;
		}
		v_lotto.push_back(cnum);
	}
	return v_lotto;
}

int CompareVec(vector<int> vec1, vector <int> vec2, int r) {
	int cnt = 0;

	// 두 벡터 비교
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (vec1[i] == vec2[j]) cnt++;
		}
	}
	return r + 1 - cnt;
}