#include "User.h"

using namespace std;

vector <int> userInput(int n1, int n2) {
	int num;
	int i = 1;
	bool dup;
	vector <int> vec;

	vec.reserve(n2);

	// ����� �Է¹ޱ� 
	std::cout << "���ڴ� 1 - " << n1 << " ������ ���ڸ� �Է��� �� �ֽ��ϴ�." << endl;

	while (vec.size() < n2) {

		dup = false;

		std::cout << endl << i << "��° ��ȣ�� �Է��ϼ��� : ";

		cin >> num;

		if (num == -1) return vec;

		if (num < 1 or 25 < num) {

			std::cout << "1 - " << n1 << " ������ ���ڸ� �Է��ϼ���." << endl;

			continue;
		}
		else {

			for (int v : vec) {
				if (num == v) {

					std::cout << endl << "�ߺ��� �����Դϴ�. " << endl;

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