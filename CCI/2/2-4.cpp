using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>

/**
 * 問題
 * - リストの分割
 * 前提
 * - 与えられているのは単方向連結リストか -> OK
 * - 最大どのくらいの長さを想定するか -> int最大長
 * - リストの長さは現状わからないですか？ -> YES
 * - リストの中身はなんですか -> int
 * - 全てのxより大きい値が右側にいる必要はない -> YES
 * 考えたこと
 * - 左から精査していって、y >= xとなる値が見つかり次第
 * - Nodeを増やす
 * - 先頭ノードにくっつける
 * - 今のノードを削除する
 * - を行えばよさそう
 */

struct Node1 {
  int data;
  Node1* next;
  Node1(int d) : data{ d }, next{ nullptr } { }
};

void outputMinDivList(Node1* list, int x) {
    Node1* tmp = list;
    while (tmp != nullptr) {
        if (tmp->data >= x) {
            Node1 first = Node1(tmp->data);
            Node1* newNode = &first;
            newNode->next = list;
            list = newNode;
            tmp->data = tmp->next->data;
            tmp->next = tmp->next->next;
        } else {
            tmp = tmp->next;
        }
    }

    while(list != nullptr) {
        cout << list->data;
        list = list->next;
    }
}

int main() {
    int N;
    cin >> N;

    int x;
    cin >> x;

    if (N == 0 || N == 1) return -1;

    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    
    for (int i = 0; i < N; ++i) cout << v[i];
    cout << x;
    
    
    Node1 first = Node1(v[0]);
    Node1* nodeList = &first;
    Node1* origin = nodeList;
    for (int i = 1; i < N; ++i) {
        Node1 node = Node1(v[i]);
        nodeList->next = &node;
        nodeList = nodeList->next;
    }

    outputMinDivList(origin, x);
    return 0;
}
