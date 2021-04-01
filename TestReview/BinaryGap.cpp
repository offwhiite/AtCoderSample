// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <sstream>
#include <stack>
using namespace std;

string toBinaryStr(int n) {
    stack<char> r;
    while(n!=0) {
        r.push((n % 2 == 0 ? '0' : '1'));
        n /= 2;
    }

    stringstream ss;
    while (!r.empty()){
        ss << r.top();
        r.pop();
    }
    return ss.str();
}

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    string str = toBinaryStr(N);
    int maxCount = 0;
    int count = 0;
    bool countStart = false;
    for (char c : str) {
        if (c == '1') {
            if (maxCount < count) {
                maxCount = count;
            }
            count = 0;
            countStart = true;
        } else {
            if (countStart) count++;
        }
    }
    return maxCount;
}