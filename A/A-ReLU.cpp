#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x < 0) {
        x = 0;
    }

    cout << x << endl;
}