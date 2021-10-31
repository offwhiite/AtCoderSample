#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 問題
 * - ループ判定
 * 前提
 * - 単方向連結リストは与えられるか -> OK
 * - 最大どのくらいの長さを想定するか -> int
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - 単純に考えれば全てのポインタをmapで保持して出てくるアドレスをカウントして、最初に２になったらそれがループの場所
 * - この場合はメモリがNかかるので、他に方法がないか考えてみる（今までの傾向から考えると他のデータ構造なしで多分できる
 * - ループする最初のノードの定義を考えてみると
 * - X->next == Y->next となる互いが異なるX,Yが見つかれば良さそう
 * - ランナーテクニックで1,2ずつ進むポインタを考えた時、二つのポインタが同じとこをさした場合は2が1に追いついた、ということで
 * - おそらくループ内に存在していることがわかるはず
 * - もしそこから一歩ずつ後ろに辿ることができれば、どこかで分岐するのでそこが最初のノードとすることができそう。
 * - 双方向ノードを使えばできるのでは、と考えたけれど、例を考えてみるとどうしてもC’ノードが存在することになってしまう。
 * - (node->back == E とnode->back == Bを持つ　Cが二つ必要なので)
 * - ので多分それは無理っぽい。
 * - ループしているので、後ろではなく前方向で考えてみる。そう考えると構造は2-7に近いかもしれない。
 * - 先頭からのポインタと、合流した時点（ループ内からスタートする）でのポインタの二つの共通する箇所を探してみる
 * - a->b->c->d->e
 * - a->c->e->d
 * - でdが合流地点
 * - dから一歩ずつ進みつつ、またここに戻ってくるときの距離を調べて、先頭ポインタからいくときの距離も同様に調べる。
 * - その距離を合わせてから一歩ずつ確認していくと出てきそうな気がする
 * - a->b->c->d 距離4
 * - d->e->c->d 距離4
 * - なのでこのまま一個ずつ辿りつつnext==nextになる場所を見つければ良さそう
 * - あってるか不安なので他の例も考える
 * - a->b->c->d->e->f->g->h->d
 * - a->c->e->g->d->f
 * - fで合流
 * - a->b->c->d->e->f 距離6
 * - f->g->h->d->e->f 距離6
 * - 謎に距離が一致する。。不思議な力で距離が一致するようになってるのかな。。
 */
struct Node {
  char data;
  Node* next;
  Node(char d) : data{ d }, next{ nullptr } { }
};

int main() {
    Node* first;
    Node* second;

    // create test case
    first = new Node('a');
    first->next = new Node('b');
    first->next->next = new Node('c');
    first->next->next->next = new Node('d');
    first->next->next->next->next = new Node('e');
    first->next->next->next->next->next = new Node('f');
    first->next->next->next->next->next->next = first->next;
    
    Node* fOri = first;
    Node* sOri = second;
    
    second = first;
    do {
        second = second->next->next;
        first = first->next;
    } while(second != first);
    
    cout << "second " << second->data << " first " << first->data << endl;
    
    first = fOri;
    
    while(first->next != second->next) {
        first = first->next;
        second = second->next;   
    }
    
    cout << first->next->data << endl;
    
}