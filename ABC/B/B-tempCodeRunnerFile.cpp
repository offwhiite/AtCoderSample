#include <iostream>
using namespace std;

bool isACGT(char a) {
    if (a == 'A' || a=='C' || a=='G' || a=='T') return true;
    return false;
}
int main(int argc, char *argv[]) {
    string S;
    cin >> S;

    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < S.length()-1; i++) {
        if (!isACGT(S[i])) continue;
        for (int j = i+1; j< S.length();j++){
            if(!isACGT(S[j])) break;
            tmp++;
        }
        if (ans < tmp) {
            ans = tmp;
        }
    }

    cout << ans << endl;
}