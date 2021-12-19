#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <time.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int d) : data(d), left(nullptr), right(nullptr){ }
};


void inOrder(Node* node, vector<int> v) {

}
/**
 * ランダムノード
 * 
 * - 追加、検索、削除の機能が同時に存在しているので、トレードオフが発生しそう
 * - 一旦全てを配列に持つことで、ランダム値が示す要素を返せばO(1)で実装できる
 * - ただし、その場合は追加検索削除をした場合に配列を直す必要がありそう。
 * - 単純に削除すると配列の詰め直しが発生してO(N)かかるようになってしまう
 *  - けど元々木構造のノード削除は結構厄介な気がする
 * - 追加、検索、削除の処理を遅くしないままランダム値を返すとなると、普通に木をランダムウォークしてノードを返すようにする
 *  - 多分O(logN)になる
 * - 木のランダムウォークをどう実装するか
 *  - 全てのノードは同確率で選ばれるようにするという条件
 *  - 例えば深さをランダム値とした場合、下に行けば行くほど選ばれる確率が少なくなる
 * - 仮に左0〜N, 右0〜Nがランダムに出るとしたらどうか。(0,0)ならルート
 *  - 存在しないノードが出る場合があってむずかしい
 *  - 存在しないノードが出たら振り直しする？（無限に終わらないかもしれない）
 *  - 
 */
int main() {

    // テストデータ
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(20);

    // array
    vector<int> v = vector<int>();

    // vに詰める
    inOrder(root, v);

    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    int r = rand() % v.size() + 1;

    cout << v[r] << endl;
}