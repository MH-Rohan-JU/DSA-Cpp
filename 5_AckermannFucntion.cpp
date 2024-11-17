#include <iostream>
using namespace std;
int Ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return Ackermann(m - 1, 1);
    else
        return Ackermann(m - 1, Ackermann(m, n - 1));
}
int main() {
    int n, m;
    cout << "Enter 2 non-negative integers: ";
    cin >> n >> m;
    cout << "Ackermann(" << n << ", " << m << ") = " << Ackermann(n, m);
    return 0;
}