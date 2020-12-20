#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

template<typename T>
std::vector<T> table(int n, T v) { return std::vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
    auto val = table(args...);
    return std::vector<decltype(val)>(n, std::move(val));
}

constexpr int dx[6] = {0, 1, 0, 2, 0, 1};
constexpr int dy[6] = {0, 0, 1, 0, 0, 1};
constexpr int dz[6] = {0, 0, 0, 0, 1, 0};

int main() {
    long long N, D;
    cin >> N >> D;

    // サイコロのでための素因数は2,3,5しかない
    // つまり、Dの素因数分解の結果でた2,3,5の冪乗の数以上の物は全て倍数となる
    // 1. まずはDの素因数分解をする
    // 1.1 2,3,5の素因数分解
    int d2 = 0, d3 = 0, d5 = 0;
    while(D % 2 == 0) { D /= 2; ++d2; }
    while(D % 3 == 0) { D /= 3; ++d3; }
    while(D % 5 == 0) { D /= 5; ++d5; }
        
    // 1.2 この時点でDが1でない場合は2,3,5以外の素因数を含んでおり、決して倍数にはならない
    if (D != 1) {
        cout << 0 << endl;
        return 0;
    }

    // 2. 次はサイコロを振った時、その2,3,5の組み合わせの数を計算していく
    // サイコロを振る回数分回す
    auto dp = table(d2 + 1, d3 + 1, d5 + 1, 0.0);
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        // 次のdpテーブル
        auto nxt = table(d2 + 1, d3 + 1, d5 + 1, 0.0);

        // 今までの積の確率全てにたいして、次のでうるサイコロの値をたす
        for (int x = 0; x <= d2; ++x) {
            for (int y = 0; y <= d3; ++y) {
                for (int z = 0; z <= d5; ++z) {
                    for (int i = 0; i < 6; ++i) {
                        // 1の場合、積の結果は増えないので、今までの結果の確率が増える
                        // 求めるのはDの倍数なので、Dの倍数より多い指数部の場合をカウントしたい
                        // そのため、d2,d3,d5を超える場合は全てd2,d3,d5の確率に足してしまう
                        const int nx = min(d2, x + dx[i]);
                        const int ny = min(d3, y + dy[i]);
                        const int nz = min(d5, z + dz[i]);
                        nxt[nx][ny][nz] += dp[x][y][z] / 6;
                    }
                }
            }
        }
        dp = move(nxt);
    }

    cout << dp[d2][d3][d5] << endl;
    return 0;
}