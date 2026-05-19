#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // dp[x]는 숫자 x를 만드는 데 필요한 최소 제곱수의 개수.
    // 처음에는 넉넉하게 가장 큰 값(자기 자신을 1^2으로만 채우는 경우인 x)으로 초기화
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i] = i; 
    }
    
    // 1부터 n까지 차례대로 최소 개수를 구하기
    for (int i = 1; i <= n; i++) {
        // i보다 작은 제곱수(j*j)들을 하나씩 빼보며 최소값을 찾는다.
        for (int j = 1; j * j <= i; j++) {
            int square = j * j;
            
            // 현재 기록된 값 vs (i에서 제곱수를 뺀 나머지를 만드는 최소 개수 + 1). 비교해서 min값 찾는다.
            dp[i] = min(dp[i], dp[i - square] + 1);
        }
    }
    
    // N을 만드는 최소 개수 출력
    cout << dp[n] << "\n";
    
    return 0;
}