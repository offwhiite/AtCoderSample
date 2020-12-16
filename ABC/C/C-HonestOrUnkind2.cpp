#include<iostream>
#include<vector>
#include <stdio.h>      
#include <stdint.h>
#include <cassert>
#include <bit>
#include <cstdint>
using namespace std;

class Testimony {
    public:
    int target;
    int isHonesty;

    Testimony() {
        target = 0;
        isHonesty = 0;
    }

    Testimony(int _target, int _isHonesty) {
        target = _target;
        isHonesty = _isHonesty;
    }
};

int popcount(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
};

int main () {
    int N;
    cin >> N;

    vector<vector<Testimony> > human(N, vector<Testimony>(0,Testimony()));
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        for (int j = 0; j < A; ++j) {
            int target, isHonesty;
            cin >> target >> isHonesty;
            // if (isHonesty == 0) {
            //     isHonesty = 1;
            // } else {
            //     isHonesty = 0;
            // }
            human[i].push_back(Testimony(target-1, isHonesty));
        }
    }

    // N人の人が正直者の場合の総当たりを行う
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        bool isAllHonesty = true;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {  
                for(int j = 0; j < human[i].size(); ++j) {      
                    if ((bit & (1 << human[i][j].target)) ^ (human[i][j].isHonesty << human[i][j].target)) {
                        isAllHonesty = false;
                    }           
                }
            }
        }

        int count = popcount(bit);
        if(isAllHonesty && count > ans) {
            ans = popcount(bit);
        }
    }

    cout << ans << endl;
}