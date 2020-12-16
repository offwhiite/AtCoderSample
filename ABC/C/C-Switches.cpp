#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, M=0;
    cin >> N >> M;

    // 電球分だけ回して、どことどこのスイッチにつながっているのかvectorで保存する
    vector<vector<int> > v(M, vector<int>(0,0));
    for (int i=0; i< M; ++i) {

        // 最初電球iには何個のスイッチが入っているかを取得する
        int switchCount = 0;
        cin >> switchCount;
        // そのあとは、電球iが何番のスイッチにつながっているかとる
        for (int j=0;j<switchCount;++j) {
            int switchNum;
            cin >> switchNum;
            v[i].push_back(switchNum);
            --v[i][j];
        }
    }

    // 電灯が点灯するのは奇数か偶数か
    vector<int> isLiteUpOddNum(0);
    // cout << "奇数かどうか";
    for (int i=0;i<M;++i) {
        int num;
        cin >> num; 
        isLiteUpOddNum.push_back(num);
        // cout << isLiteUpOddNum[i];
    }

    // bit探索を行う:全てのスイッチパターンを試す
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {

        bool isAllLightUp = true;
        // あるスイッチパターンbitの時、電球iは点灯するか
        for (int i = 0; i < M; ++i) {
            int onSwitchNum = 0;

            // 何個スイッチが押されているか
            for (int j = 0; j < v[i].size(); j++) {
                if (bit & (1 << v[i][j])) {
                    onSwitchNum++;
                }
            }
            // 一個でも点灯してない電球があったらfalseにする
            if (onSwitchNum % 2 != isLiteUpOddNum[i]) isAllLightUp = false;
        }
        if (isAllLightUp) ans++;
    }

    cout << ans << endl;
    return 0;
}