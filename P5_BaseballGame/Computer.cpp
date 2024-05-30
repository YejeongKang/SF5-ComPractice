#include <vector>
#include <random>
#include <iostream>

#include "Computer.h"

vector <int> cRandVec;
int cnt;

vector <int> generateRandNum(int r)
{
	int cnum;
	cRandVec.reserve(r);

	// 랜덤 수 뽑기
	while(cRandVec.size() < r) {

		cnum = rand() % 9 + 1;

		for (int l : cRandVec) {

			if (cnum == l) continue;

		}
		cRandVec.push_back(cnum);
		
	}
	return cRandVec;
}


bool check(vector<int> vec1, vector <int> vec2, int r, int &cnt)
{
	int strikeCnt = 0;
	int ballCnt = 0;
	bool flag = false;

	cnt++;

	// 스트라이크, 볼 판정
	for (int i = 0; i < 3; i++)
	{
		if (vec2[i] == vec1[i])
		{
			strikeCnt++;
			continue;
		}

		for (int j = 0; j < 3; j++)
		{
			if(vec2[i] == vec1[j])
			{
				ballCnt++;
			}
		}
	}

	if (strikeCnt == 3)
	{
		flag = true;
		cout << cnt << "번 만에 맞혔습니다.";
		return flag;
	}

	cout << "Strike : " << strikeCnt << "\t" << "Ball : " << ballCnt << endl;
		
	return flag;
}
