#include <iostream>
#include <math.h>
using namespace std;

int main(int argv, char* argc[]) {
    long N = 0;
    cin >> N;

    long sqrtN = sqrt(N);
    
    int output = 0;
    for (int i=1; i <= sqrtN; i++) {
        if (N%i==0) {
            int ans = N/i;
            output = to_string(ans).length();
        }
    }

    cout << output << endl;
}