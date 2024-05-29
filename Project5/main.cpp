#include <iostream>

#include "Computer.h"
#include "User.h"

using namespace std;

#define RAND 3

int main()
{
	vector<int> computerNum, userNum;
	cout << "야구 게임" << endl << endl;

	computerNum = generateRandNum(RAND);

	// 사용자 입력 받고 비교하기
	int n1, n2, n3;
	int cnt = 0;
	bool flag;

	while (1)
	{
		cout << "1 ~ 9 사이의 숫자 3개를 입력하시오 (이외의 숫자: 종료)" << endl;

		cin >> n1 >> n2 >> n3;

		if (0 < n1 && n1 < 10 && 0 < n2 && n2 < 10 && 0 < n3 && n3 < 10)
		{
			userNum = inputVector(n1, n2, n3);
			flag = check(computerNum, userNum, RAND, cnt);

			if (flag) return 0;
			
		}
		
		else
		{
			cout << "게임을 종료합니다.";
			return 0;
		}
	}
}