#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 前提
 * - 文字はASCIIとします
 * - 入力されてくる文字列はコンソールからくるでいいですか？ // Yes
 * - 文字列はどのくらいの大きさですか？int型でおさまる長さでしょうか？ // Yes
 * - 空白も一つの文字としますか？ // No
 * - UpperCase と LowerCaseは区別しますか？ // No
 * - この文字列は直接操作しても良いか // Yes
 * 
 * 基本方針
 * - 愚直にやると、実際の操作のシミュレーションを行えば良さそう。
 * - 要するに、文字列を比較していって、異なる場所が見つかればinsert or remove or replaceを仕掛ける
 * -> でも区別つかなくないか？例えば abc aabcだった時にremoveするのかreplaceが必要なのかをv[1]の時点で把握する厳しい
 * -> 次の文字も確認しよう。もし次の文字が今の文字と一致だったらremove、次の文字が次の文字と一致だったらreplaceとする
 * -> つまりこう
 *  -> もしa[i] != b[i] なら 
 *  -> a[i]==b[i+1] ならremove
 *  -> a[i+1]==b[i+1] ならreplace
 *  -> a[i+1]==b[i]ならinsert
 * -> これで二回目の問題に当たったらFalse,あたらなかったらtrue
 * -> これはO(N)で行けそう(多分)
 * - 他の方法はあるか
 * - これもHashMapに持てば解決する気がする。
 * - 1-2あたりで使ったhashmapの数字差分を使う
 * - 文字列aをhashmapに入れる。map[a]++;
 * - 文字列bをhashmapから引く。map[b]--;
 * - その時の残りの値が以下のようになればいける
 * - mapのvalueに
 *  - 1が一個だけある -> insert
 *  - -1が一個だけある -> remove
 *  - 1,-1が一個ずつある -> replace
 *  - それ以外はむり
 * - これも計算量的にはO(N)かな。hashMapを使う分だけ空間計算量がかかるのでこの場合前者の方がいいかも
 */

// 大文字は全て小文字として考える
char asciiToLowerWithAlphabet(char c) {
    if (c <= 'Z' && c >= 'A') return c - ('Z' - 'z');
    return c;
}

int main() {
    string a,b;
    cin >> a >> b;

    // 文字比較をしたいので小文字化する
    transform(a.begin(), a.end(), a.begin(), asciiToLowerWithAlphabet);
    transform(b.begin(), b.end(), b.begin(), asciiToLowerWithAlphabet);

    // 差が1以上あるならばもう終了。
    int d = a.length() - b.length();
    if (abs(d) > 1) {
        cout << "False" << endl;
        return 0;
    }

    bool oneCount = false;
    for (int i = 0; i < min(a.length(), b.length()); ++i) {
        if (a[i]==b[i]) continue;
        else if (oneCount) {
            // 違う文字が二回出てきたらアウト
            cout << "False" << endl;
            return 0;
        } else {
            // 違う文字が出てきた場合
            if (a[i]==b[i+1]) b.erase(i,1); // i番目の一つの要素を削除
            else if (a[i+1]==b[i+1]) b.replace(i, 1, string(1, a[i])); // i番目の一つの要素を入れ替え
            else if (a[i+1]==b[i]) b.insert(i, string(1,a[i])); // i番目の一つの要素を追加
            // oneCount をtrueにする
            oneCount=true;  
        }
    }

    cout << "True" << endl;
    return 0;
}