#include<stdio.h>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int N=0;
    std::cin >> N;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i*j==N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}