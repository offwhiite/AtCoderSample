#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>; // グラフ構造

struct Node {
  int data;
  Node* parent;
  Node* left;
  Node* right;
  Node(int d) : data{ d }, parent{ nullptr } , left{nullptr}, right{nullptr}{ }
};


void inorder(Node* node) {
    if(node->left != nullptr)inorder(node->left);
    cout << " " << node->data;
    if(node->right != nullptr)inorder(node->right);
}


/**
 * 次のノード
 * 
 * - 多分visitというログを使わずに次に訪れるノードを探す必要がある。
 * - そして通常探索している再帰処理もないので、自力で見つけないといけない。
 * - 自分自身が今どこにいるかを知る必要がある
 * - もし現在のノードが与えられた時、それはすでに左のノードは行き尽くしているという考え方で良い...？
 * - 自分が左ノードだった場合
 *  - もし右があれば右ノードの左奥（普通に右側からin-order処理をする
 *  - 右がなければ親
 * - 自分が右ノードだった場合
 *  - もし右があれば右ノードの左奥（普通に右側からin-order処理をする
 *  - 右がなければ自分自身を返す
 */
int main() {

    // テストデータ
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(20);

    inorder(root);
    return 0;
}