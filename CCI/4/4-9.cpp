
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
using Graph = vector<vector<int>>; // グラフ構造

struct Node {
  int data;
  Node* parent;
  Node* left;
  Node* right;
  bool isVisit = false;
  Node(int d) : data{ d }, parent{ nullptr } , left{nullptr}, right{nullptr}{ }
};

int main() {
    
        // テストデータ
    Node* root = new Node(8);
    root->left = new Node(4);
    root->left->parent = root;
    root->right = new Node(10);
    root->right->parent = root;
    root->left->left = new Node(2);
    root->left->left->parent = root->left;
    root->left->right = new Node(6);
    root->left->right->parent = root->left;
    root->right->right = new Node(20);
    root->right->right->parent = root->right;

    // 与えられたノード
    Node* node1 = root->left;
    // node1->isVisit = true; // 自分自身を含めてしまうと、上位ノードという条件を満たせない
    Node* node2 = root->left->right;
    // node2->isVisit = true;
    
    // 初期位置が一緒だったらその親を返す
    if (node1 == node2) {
        cout << node1->parent->data << endl;
        return 0;
    }
    
    // 親を遡ってメモしてく
    while(node1 != nullptr && node2 != nullptr) {
        if (node1 != nullptr) {
            node1 = node1->parent;
            // すでに訪れているのであれば、そこが共通親ノードのはず
            if (node1 != nullptr && node1->isVisit == true) {
                cout << node1->data << endl;
                return 0;
            } else if (node1 != nullptr) {
                // そうでなければ今のノードを訪れたことにする
                node1->isVisit = true;
            }
        }
        
        if (node2 != nullptr) {
            node2 = node2->parent;
            if (node2 != nullptr && node2->isVisit == true) {
                cout << node2->data << endl;
                return 0;
            } else if (node2 != nullptr) {
                node2->isVisit = true;
            }
        }
    }
    
    cout << "not found" << endl;
}