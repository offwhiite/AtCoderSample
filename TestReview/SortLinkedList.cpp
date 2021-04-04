#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* node;
};

/**
 * 作戦として、まず最初に全てのノードをくっつけて一つのリストにする
 * - そのあとは単純にバブルソートしてみる
 */
Node* mergeLinkedList(Node* nodeList[], int listSize) {
    // 最初のノードの最後を求める
    Node* root = nodeList[0];

    // 次にリストを一本にする
    int size = 0;
    while(root->node != nullptr) {
        root = root->node;
        if (root->node == nullptr) {
            size++;
            if (size < listSize) root->node = nodeList[size];
        }
    }

    // あとはバブルソートする
    root = nodeList[0];
    while(root->node != nullptr) {
        Node* next = root->node;
        while(next->node != nullptr) {
            if (root->data > next->data) {
                int tmp = root->data;
                root->data = next->data;
                next->data = tmp;
            }
            next = next->node;
        }
        root = root->node;
    }

    return nodeList[0];
}

Node* newNode(int data) {
    struct Node* temp = new Node;
    temp->data = data;
    temp->node = NULL;
    return temp;
}

int main() {
    Node* arr[3];
 
    arr[0] = newNode(1);
    arr[0]->node = newNode(3);
    arr[0]->node->node = newNode(5);
    arr[0]->node->node->node = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->node = newNode(4);
    arr[1]->node->node = newNode(6);
    arr[1]->node->node->node = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->node = newNode(9);
    arr[2]->node->node = newNode(10);
    arr[2]->node->node->node = newNode(11);
    Node* root = mergeLinkedList(arr, 3);

    while(root->node != NULL) {
        cout << root->data << " ";
        root = root->node;
    }
    cout << endl;
    return 0;
}