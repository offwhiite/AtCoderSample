#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

/**
 * 前提
 * - 文字はASCIIとします
 * - 入力されてくる文字列はコンソールからくるでいいですか？ // Yes
 * - 文字列はどのくらいの大きさですか？int型でおさまる長さでしょうか？ // Yes
 * - 出力はtrue / falseだけで、その発生しうる辞書の文字列自体を出力することはないですか？ // Yes
 * - アルファベットと空白だけ考慮するで良いでしょうか？ // Yes
 * - 空白も一つの文字としますか？ // No
 * - UpperCase と LowerCaseは区別しますか？ // No
 * 
 * 基本方針
 * - 愚直にやると、文字列の順列探索を行う。c++だとstd::next_permutationで文字列を生成できる
 * - 上記の場合順列となるので、N!/(N-N)! = O(N!) 前と後ろから探索にO(N)。支配的なのはO(N!)
 * - これは多分20文字あたりでもうアウト(10^18を超えちゃうので64bitの型でもオーバーしちゃう)
 * - 回文という特性から、同じ文字が偶数個と奇数の文字が1つor0つあれば良いので、今回はそちらで計算する
 * - この場合はO(2N) = O(N)となる 
 */

// 大文字は全て小文字として考える
char asciiToLowerWithAlphabet(char c) {
    if (c <= 'Z' && c >= 'A') return c - ('Z' - 'z');
    return c;
}
int main() {
    string N;
    cin >> N;
    map<char, int> m;

    transform(N.begin(), N.end(), N.begin(), asciiToLowerWithAlphabet);
    for (int i = 0; i < N.length(); ++i) {
        if (N[i] == ' ') continue;
        m[N[i]]++;
    }

    int oneCount = 0;
    for (auto a : m) {
        cout << "f = " << a.first << " s = " << a.second << endl;
        if (a.second % 2 == 0) continue;
        else if(a.second % 2 == 1) oneCount++;
        else { cout << "False" << endl; return 0; }
    }
    cout << "True" << endl;
    return 0;
}