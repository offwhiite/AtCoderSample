#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

/**
 * 問題
 * - 重複要素の削除：ソートされていない連結リストから、重複する要素を削除するコードを書いてください
 * 前提
 * - 与えられているのは単方向連結リストか -> OK
 * - 最大どのくらいの長さを想定するか -> int最大長
 * - リストの長さは現状わからないですか？ -> YES
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - バッファを利用していいのであれば、取得したノードの情報を常に HashMapに保存しておき、すでに登場しているかどうかを調べながら実施するとよさそう。
 * - この場合の計算量はO(N)
 * - もしバッファを利用しないのであれば、ソートしてしてしまって重複が続く限り飛ばしていくのがよさそう。
 * - この場合は計算量O（NlogN）
 */
struct Node {
  int data;
  Node* next;
  Node(int d) : data{ d }, next{ nullptr } { }
};

Node* removeDuplicate(Node* node) {
    Node* origin = node;
    map<int, bool> m;

    Node* back = node;
    while (node->next != nullptr) {
        if (m[node->data] == false) {
            m[node->data] = true;
            back = node;
            node = node->next;
        } else {
            back->next = node->next;
            node = node->next;
        }
    }

    return origin;
}
int main() {
    
    return 0;
}