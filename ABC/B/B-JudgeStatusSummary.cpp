#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    map <string, int> S;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        if (tmp == "AC") {
            S["AC"]++;
        } else if (tmp == "WA") {
            S["WA"]++;
        } else if (tmp == "TLE") {
            S["TLE"]++;
        } else if (tmp == "RE") {
            S["RE"]++;
        }
    }

    cout << "AC x " << S["AC"] << endl;
    cout << "WA x " << S["WA"] << endl;
    cout << "TLE x " << S["TLE"] << endl;
    cout << "RE x " << S["RE"] << endl;
}