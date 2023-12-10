#include <iostream>
using namespace std;
int recursiveMultiply(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return recursiveMultiply(a - 1, b) + b;
}

int main() {
    int result = recursiveMultiply(5, 3);
    cout << "Result: " << result <<endl;

    return 0;
}
