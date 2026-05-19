#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);
    int l = x * y / g;
    cout << g << "\n" << l;
    return 0;
}