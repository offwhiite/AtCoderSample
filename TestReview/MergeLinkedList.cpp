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
 * 作戦として、すでにソート済みらしいのでpeekしていく。
 */
Node* mergeLinkedList(Node* nodeList[], int listSize) {
    Node* root = new Node;
    Node* origin = root;    
    while(true) {
        bool isFinished = true;
        int value = INT32_MAX;
        int position = 0;
        for (int i = 0; i < listSize; ++i) {
            if(nodeList[i] == NULL) continue;
            if(value >= nodeList[i]->data) {
                value = nodeList[i]->data;
                position = i;
            }
            isFinished = false;
        }
        if (isFinished) break;
        Node* next = new Node;
        root->data = value;
        root->node = next;
        root = root->node;
        nodeList[position] = nodeList[position]->node;
    }

    return origin;
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