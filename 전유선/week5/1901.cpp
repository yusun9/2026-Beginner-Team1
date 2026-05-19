#include <iostream>

using namespace std;

// 어떤 수 n이 소수인지 판별하는 간단한 함수
bool isPrime(int n) {
    if (n < 2) return false; // 1 이하는 소수가 아님

    // 2부터 n의 제곱근까지 나누어 떨어지는지 확인
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // 나누어 떨어지면 소수가 아님
    }
    return true; // 위 조건을 모두 통과하면 소수
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        int diff = 0; // 거리(차이)를 0부터 시작

        while (true) {
            int lower = m - diff; // m보다 작은 방향
            int upper = m + diff; // m보다 큰 방향

            // 문제 조건: 출력되는 소수는 1 이상 1,000,000 이하이어야 함
            bool lower_ok = (lower >= 1 && lower <= 1000000 && isPrime(lower));
            bool upper_ok = (upper >= 1 && upper <= 1000000 && isPrime(upper));

            // 1. 만약 아래쪽, 위쪽 둘 다 소수를 찾았다면 break (두 수가 다를 때만)
            if (lower_ok && upper_ok && lower != upper) {
                cout << lower << " " << upper << "\n";
                break; // 찾았으니 탈출
            }
            // 2. 아래쪽만 소수이거나, m 자체가 소수인 경우 (lower == upper)
            else if (lower_ok) {
                cout << lower << "\n";
                break;
            }
            // 3. 위쪽만 소수인 경우
            else if (upper_ok) {
                cout << upper << "\n";
                break;
            }

            diff++; // 소수를 못 찾았다면 거리를 1 늘려서 다시 확인
        }
    }

    return 0;
}