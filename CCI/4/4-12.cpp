#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <stack>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int d) : data(d), left(nullptr), right(nullptr){ }
};

void calcMatch(stack<int> stack, int target) {
    vector<int> v;
    while(!stack.empty()) {
        v.push_back(stack.top());
        stack.pop();
    }

    // 最大63個まで
    long long n = v.size();

    // 何個同時にフラグを建てるか
    for (long long i = 1; i < n; ++i) {
        long long bit = 1;

        // i個のフラグを何個建てる
        for (long long k = 1; k < i; ++k) {
            bit = bit << 1;
            bit += 1;
        }

        while(bit < (1 << n)) {
            long long sum = 0;
            vector<int> route;
            for (int l = 0; l < n; ++l) {
                if (bit & (1 << l)) {
                    sum += v[l];
                    route.push_back(v[l]);
                }
            }
            if (sum == target) {
                for(int count = 0; count < route.size(); ++count) {
                    cout << route[count] << "-";
                }
                cout << ":" << sum << endl;
            }
            bit = bit << 1;
        }
    }
}
void preOrder(Node* node, stack<int> stack, int target) {
    stack.push(node->data);
    if(node->left != nullptr)preOrder(node->left, stack, target);
    calcMatch(stack, target);
    if(node->right != nullptr)preOrder(node->right, stack, target);
    calcMatch(stack, target);
}

/**
 * 合計値が等しい経路
 * 
 * - 1.単純にやるとすれば、各ノードから探索を始めて最後まで探索していく間足し続ければ良さそう。
 *  - そうすると無駄に同じ計算をしていく場合があるはず。これをなくすにはどうすれば良いか。
 * - 2. 一番最後まで到達した後、組み合わせ計算をする
 *  - 全てのノードの組み合わせをする必要はなく、隣り合ったノードの組み合わせになるはず。
 *   - 例えば4つのノードがあった時、10個の組み合わせで良い
 *     - 0001
 *     - 0010
 *     - 0011
 *     - 0100
 *     - 0110
 *     - 0111
 *     - 1000
 *     - 1100
 *     - 1110
 *     - 1111
 *   - これは単純全探索よりは良いが、同じ計算を繰り返してしまうのは変わりなさそう
 *  - 3. 末尾が変わるだけであれば、（追加のノードが増えるだけであれば）それまでの組み合わせについては計算済みなのでスキップする
 *   - 各ノード自体に今までの合計値を持つ
 *    - [0] 自分自身
 *    - [1] 自分自身と親ノード
 *    - [2] 自分自身と親ノードと親ノードの親ノード
 *   - 次のノードはm[0], m[0] + n[0], m[0] + n[1]となっていく
 *   - 探索しながら計算していくので、多分O(n)
 */
int main() {

    stack<int> stack;

    // テストデータ
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(20);

    // 探索開始
    preOrder(root, stack, 12);
}