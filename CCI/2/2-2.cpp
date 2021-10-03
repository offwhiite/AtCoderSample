#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 問題
 * - 後ろからK番目を返す：単方向連結リストに置いて、末尾から数えてK番目の要素を見つけるアルゴリズムを実装してください
 * 前提
 * - 単方向連結リストは与えられるか -> OK
 * - 最大どのくらいの長さを想定するか -> int
 * - リストの長さは現状わからないですか？ -> YES
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - 末尾から数えて、なのでまず全体の長さが知りたい
 * - なので普通にやっていくなら順序よく見ていくことでサイズNを確定させる
 * - 単方向リストなので、後ろに戻れない
 * - そのためNを確定させたらN-K回進めば良さそう。計算量はO(2N)
 * - ランナーテクニックを使うのであれば、次の次のポインタを構造に持っておきたい
 * - そうすればN/2で最大長がわかる
 */
class Node1 {
  int data;
  Node1* next;
  Node1(int d): data{d}, next{ nullptr } { }
  Node1* getReverseWith(int k) {
    // このNodeの後ろからK番目のポインタに移動する
    Node1 *now = next;
    int length = 0;
    while(now->next != nullptr) {
      now = now->next;
      length++;
    }
    if (length == 0) {
      return nullptr; // lengthが0ということはそんなものはないので
    }

    now = next;
    for (int i = 0; i < length - k; ++i) {
      now = now->next;
    }
    return now;
  }
};
