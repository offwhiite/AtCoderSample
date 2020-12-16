#include<iostream>
using namespace std;
int main() {
    string S, T;
    std::cin >> S >> T;

    int maxCount = 0;
    for (int i = 0; i <= S.length() - T.length(); ++i) {
        int count = 0;
        for (int j = 0; j < T.length(); ++j) {
            if (S[i + j] == T[j]) {
                count++;
            }
        }
        if (maxCount < count) {
            maxCount = count;
        }
    }

    cout << T.length() - maxCount << endl;
    return 0;
}