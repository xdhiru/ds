#include <iostream>
using namespace std;

int fib(int a) {
    if (a == 0) {
        return 0;
    }
    if (a == 1 || a == -1) {
        return 1;
    }

    if (a > 1) {
        return fib(a - 1) + fib(a - 2);
    } else {
        return fib(a + 2) - fib(a + 1);
    }
}

int main() {
    cout << fib(-4) << endl;
    cout << fib(4) << endl;
    return 0;
}
