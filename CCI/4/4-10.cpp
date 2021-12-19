#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using Graph = vector< vector<int> >; // グラフ構造

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int d) : data(d), left(nullptr), right(nullptr){ }
};


Node* inorder(Node* T1, Node* T2) {
    return T1;
};

bool isMatchTree(Node* T1, Node* T2) {
    cout << T1 << " " << T2 << endl;
    // 両方ともnullptrなら一致と見做して良い
    if (T1 == nullptr && T2 == nullptr) {
        cout << "both of null" << endl;
        return true;
    } else if (T1 != nullptr && T2 == nullptr) {
        cout << "T2 one is null" << endl;
        // T2だけがnullなら（T1に続きがあるなら）それは正解として良さそう
        return true;
    } else if (T1 == nullptr && T2 != nullptr) {
        cout << "T1 one is null" << endl;
        // T1だけがnullなら（T2に続きがあるなら）それはだめ
        return false;
    } else if (T1->data != T2->data) {
        cout << "not equals" << endl;
        // データの不一致が発生したらそれはそれでだめ
        return false;
    } else {
        cout << "check next" << endl;
        return isMatchTree(T1->left, T2->left) && isMatchTree(T1->right, T2->right);
    }
};
/**
 * 部分木チェック
 * 
 * - rootを探して、そこから探索していって値が一致すれば良い
 * - 単純に同じ値= 同一ノードとする
 * - 二つの木を全て探索して、それが部分的に存在するかを見る
 * - 全て捜査して、同じ文字列が出てきたら終了の方が単純かもしれない
 *  - ただしその場合は単純に文字列にしてしまうと木の構造情報がなくなってしまう気がする
 *  - 終端に着いたら終端ノードを追加すると解消できるかもしれない
 * 
 */
int main() {

    // テストデータ
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(20);


    Node* T2 = new Node(8);
    T2->left = new Node(4);
    T2->right = new Node(10);

    Node* result = inorder(root, T2);
    if (result == nullptr) {
        cout << "not found root";
    }

    string answer;
    if (isMatchTree(result, T2)) {
        answer = "true";
    } else {
        answer = "false";
    }
    cout << "isMatch :" << answer << endl;
}