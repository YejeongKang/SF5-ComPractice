#include <iostream>

#include "Computer.h"
#include "User.h"

using namespace std;

#define RAND 3

int main()
{
	vector<int> computerNum, userNum;
	cout << "�߱� ����" << endl << endl;

	computerNum = generateRandNum(RAND);

	// ����� �Է� �ް� ���ϱ�
	int n1, n2, n3;
	int cnt = 0;
	bool flag;

	while (1)
	{
		cout << "1 ~ 9 ������ ���� 3���� �Է��Ͻÿ� (�̿��� ����: ����)" << endl;

		cin >> n1 >> n2 >> n3;

		if (0 < n1 && n1 < 10 && 0 < n2 && n2 < 10 && 0 < n3 && n3 < 10)
		{
			userNum = inputVector(n1, n2, n3);
			flag = check(computerNum, userNum, RAND, cnt);

			if (flag) return 0;
			
		}
		
		else
		{
			cout << "������ �����մϴ�.";
			return 0;
		}
	}
}