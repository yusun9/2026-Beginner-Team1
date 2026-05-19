#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++) {
        dp[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            int square = j * j;

            dp[i] = min(dp[i], dp[i - square] + 1);
        }
    }

    while (n--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}