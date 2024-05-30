#include "Calculate.h"

int main() {
    int cnt = 0;
    float num2, result;
    string oper, how;

    while (1) {
        if (cnt == 0) {
            // 첫 시도에만 num1을 직접 받기
            cout << "숫자를 입력하세요 : ";
            cin >> Calculate::num1;
            cout << endl;

            if (Calculate::num1 == -1) return 0;
        }
        else {
            cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : ";
            cin >> how;

            if (how == "Y") {
                // 두 번째 시도에는 이전 계산 결과 값을 num1으로 사용
                Calculate::num1 = result;
            }
            else if (how == "AC") {
                cout << "계산을 초기화합니다." << endl;
                cnt = 0;
                continue;
            }
            else if (how == "EXIT") {
                cout << "계산을 종료합니다." << endl;
                return 0;
            }
        }

        cout << "연산자를 입력하세요 : ";
        cin >> oper;
        cout << endl;

        if (oper == "-1") return 0;

        cout << "숫자를 입력하세요 : ";
        cin >> num2;
        cout << endl;

        if (num2 == -1) return 0;

        Calculate* res = nullptr;

        if (oper == "+") {
            res = new Addition(Calculate::num1, num2);
        }
        else if (oper == "-") {
            res = new Subtraction(Calculate::num1, num2);
        }
        else if (oper == "*") {
            res = new Multiplication(Calculate::num1, num2);
        }
        else if (oper == "/") {
            res = new Division(Calculate::num1, num2);
        }

        if (res != nullptr) {
            result = res->cal();
            delete res; // 메모리 해제
        }
        else {
            cout << "유효하지 않은 연산자입니다." << endl;
            continue;
        }

        cout << "-------------------------" << endl << "결과 : " << result << endl;

        cnt++;
    }
}
