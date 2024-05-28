#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int num, y, x, input;

	num = 0;

	while (1) {
		cout << "마방진의 행 혹은 열의 수를 자연수(홀수)로 입력해주세요 (종료: -1) : ";
		cin >> num;

		if (num > 0 and num % 2 != 1) {
			cout << "홀수 값만 입력할 수 있습니다." << endl << endl;

			continue;
		}
		else if(num <= 0 and num != -1){
			cout << "자연수 값만 입력할 수 있습니다." << endl << endl;

			continue;
		}
		else if (num == -1) {
			cout << "-1 입력. 종료합니다." << endl;
			return 0;
		}
		
		break;
	}

	// 마방진 행렬(2차원 동적 배열) 생성
	int** arr = new int* [num];

	for (int i = 0; i < num; i++) {

		arr[i] = new int[num];
	}

	// 첫 행의 가운데에 1 입력
	y = 0;
	x = ceil(num / 2);
	
	// 행렬에 값 입력
	for (int input = 1; input < pow(num,2) + 1; input++) {

		arr[y][x] = input;

		if (input % num == 0) {
			y++;
		}
		else {
			if (y == 0) {
				y = num - 1;
			}
			else {
				y--;
			}

			if (x == num - 1) {
				x = 0;
			}
			else {
				x++;
			}
		}
	}

	// 마방진 행렬 출력
	for (int i = 0; i < num; i++) {
		cout << endl;
		for (int j = 0; j < num; j++)
			cout << arr[i][j] << "\t";
	}

	// 동적 배열 해제(반납)
	for (int i = 0; i < num; i++) {
	
		delete[] arr[i];
	}
	delete[] arr;

}