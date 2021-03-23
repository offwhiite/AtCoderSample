#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 問題
 * - 間の要素を削除：単方向連結りすとに置いて、間の要素（必ずしもちょうど中央というわけではなく、
 *   最初と最後の要素以外で、その要素のみアクセス可能であるとします。
 * 　その要素を削除するアルゴリズムを実装してください
 * 前提
 * - 単方向連結リストは与えられるか -> OK
 * - 最大どのくらいの長さを想定するか -> int
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - 要するに与えられた要素Cは、nextしか分からず、自分が参照されているオブジェクトに関して知らない。これが厄介。
 * - どうやってCを削除するか。
 * - Cを削除するのは無理なので、実質C=Dとするしかないのでは。
 * - つまりCのデータをDで上書きして、CのnextをEとする
 * - そうするとBは見かけ上Dを刺すことになって、DはそのままEをさせる
 * - ノードが一個しかない場合は？どうする？
 *  - 今回の場合、次がない場合は削除しない（そもそもでない）
 *  - 削除したい場合はEmptyノード的なものが欲しい。末尾につけても良いか確認する。
 *  - Emptyノードはdata に IntMINが入っているとする
 */
struct Node1 {
  int data;
  Node1* next;
  Node1(int d) : data{ d }, next{ nullptr } { }
};

void deleteNow(Node1 *node) {
    if (node->next == nullptr) {
        Node1 empty(INT32_MIN);
        node->next = &empty;
    }
    Node1 *nextNode = node->next;
    node->data = nextNode->data;
    node->next = nextNode->next;
}