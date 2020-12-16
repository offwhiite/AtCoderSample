#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int N=0;
    string S;

    cin >> N;
    cin >> S;

    int count = 0;
    for (int i=0; i < N-2; i++) {
      if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') count ++;
    }

    cout << count << endl;
}