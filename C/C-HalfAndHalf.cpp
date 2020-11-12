#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;
    for (int i=0; i <= 100000; i++) {
        int tmp = i * 2 * C + max(0, A * (X - i)) +  max(0, B * (Y - i)) ;
        if (ans == 0) ans = tmp;
        else if (ans > tmp) {
            ans = tmp;
        }

        if (max(0, A * (X - i)) == 0 && max(0, B * (Y - i)) == 0) break;
    }
    
    cout << ans << endl;
    return 0;
}