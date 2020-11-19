#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

int main() {
 
    long a,b,c,d;
    cin >> a >> b >> c >> d;

    long ans = LONG_MIN, tmp;
    if(ans < a * c) ans = a * c; 
    if(ans < a * d) ans = a * d; 
    if(ans < b * c) ans = b * c; 
    if(ans < b * d) ans = b * d; 

    cout << ans << endl;
    return 0;
}