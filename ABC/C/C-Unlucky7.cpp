#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N ; ++i) {

        string ten = to_string(i);
        stringstream eightS;
        eightS << oct << i;
        string eight = eightS.str();
        if (ten.find('7') == string::npos && eight.find('7') == string::npos) ans++;
    }
    cout  << ans << endl;
    return 0;
}