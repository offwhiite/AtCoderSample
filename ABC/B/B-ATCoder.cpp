#include <iostream>
using namespace std;

bool isACGT(char a) {
    if (a == 'A' || a=='C' || a=='G' || a=='T') return true;
    return false;
}
int main(int argc, char *argv[]) {
    string S;
    cin >> S;

    
    int ans = 0;
    for (int i = 0; i < S.length(); i++) {
        if (!isACGT(S[i])) continue;
        int tmp = 1;
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