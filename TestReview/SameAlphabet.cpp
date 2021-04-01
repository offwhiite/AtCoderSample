#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

int main() {
    string W;
    cin >> W;
    vector <string> v;
    string inputStr = "";
    while (true) {
        cin >> inputStr;
        if (inputStr == ".") break;
        v.push_back(inputStr);
    }
    map<char, int> mw;
    for (char c : W) mw[c]=1;

    int count = 0;
    map<string, bool> answerMap;
    for (string s : v) {
        if (answerMap[s] == true) continue;
        map<char, int> mwc = mw;
        bool isSimilar = true;
        for (char c : s) {
            mwc[c]++;
            if (mwc[c] < 2) {
                isSimilar = false;
                break;
            }
        }
        if (isSimilar) {
            answerMap[s] = true;
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}