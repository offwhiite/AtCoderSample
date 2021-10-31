#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 問題
 * - 回文かどうかを判定する
 * 前提
 * - 単方向連結リストは与えられるか -> OK
 * - 最大どのくらいの長さを想定するか -> int
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - ぱっと見再帰処理で解けそうな感じがする
 * - 一番最後まで検索して、同時に先頭アドレスを保持してそこから一致を確認していく
 */
struct Node {
  int data;
  Node* next;
  Node(int d) : data{ d }, next{ nullptr } { }
};

class PalindromeCheck {
    Node* node;
    bool isPalin;

    PalindromeCheck isPalindrome(Node* checkNode) {
        PalindromeCheck p;
        if (checkNode->next != nullptr) {
            p = isPalindrome(checkNode->next);
        }

        p.isPalin = p.isPalin && checkNode->data == p.node->data;
        p.node = p.node->next;
        return p;
    }
};
