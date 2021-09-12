#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <sstream>
using namespace std;

/**
 * 1.9 文字列の回転
 * 
 * 前提
 * - 文字はASCIIとします
 * - 入力されてくる文字列はコンソールからくるでいいですか？ // Yes
 * - 文字列はどのくらいの大きさですか？int型でおさまる長さでしょうか？ // Yes
 * - 出力はtrue / falseだけで、その発生しうる辞書の文字列自体を出力することはないですか？ // Yes
 * - アルファベットと空白だけ考慮するで良いでしょうか？ // Yes
 * - 空白も一つの文字としますか？ // No
 * - UpperCase と LowerCaseは区別しますか？ // No
 * 
 * 考え方
 * - 単純に考えると文字列を一個ずつ後ろに回して一致するか調べていく
 * - それだとisSubstring 一発ではできない。
 * - 文字列の回転の通り、輪っかにしてみたときに同一のものができれば良い（先頭と後ろは繋がっている
 * - ので、s2とs2を繋げた時にs1が登場していればよいはず
 * @return int 
 */


bool isSubstring(string s1, string s2) {
    bool isSubString = false;
    if (s2.find(s1) != string::npos) isSubString = true;

    return isSubString; 
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    std::stringstream ss;
    ss << s2 << s2;

    if (isSubstring(s1,ss.str())) {
        cout << "true";
    } else cout << "false";
    cout << endl;
    return 0;
}
