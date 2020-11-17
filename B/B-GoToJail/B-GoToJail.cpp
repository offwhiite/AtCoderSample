#include <iostream>
#include <vector>
using namespace std;

#ifndef INCLUDED_B_GoToJail_h_
#define INCLUDED_B_GoToJail_h_

bool isDoubletThreeOrMore(vector<vector<int> > v);

#endif

bool isDoubletThreeOrMore(vector<vector<int> > v) {
    bool isDoubletThreeOrMore = false;
    int doubleCount = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i][0] == v[i][1]) {
            doubleCount++;
            if (doubleCount >= 3) {
                isDoubletThreeOrMore = true;
            } 
        } else {
            doubleCount = 0;
        }
    }

    return isDoubletThreeOrMore;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int> > v(N, vector<int>(2,0));
    for (int i = 0;i < N; ++i) {
        cin >> v[i][0] >> v[i][1];
    }

    if (isDoubletThreeOrMore(v)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    cout << endl;
}