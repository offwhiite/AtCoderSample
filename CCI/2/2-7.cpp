#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 問題
 * - 共通かどうかを判定する
 * 前提
 * - 単方向連結リストは与えられるか -> OK
 * - 最大どのくらいの長さを想定するか -> int
 * - リストの中身はなんですか -> int
 * 考えたこと
 * - 共通の意味を考えた時、単方向リストなので共通のノードがあった場合は以降同じノードを指すことになる（と思う
 * - ので、後ろから遡って、どっかで一致しなくなればよさそう
 */
struct Node {
  int data;
  Node* next;
  Node(int d) : data{ d }, next{ nullptr } { }
};

class CommonCheck {
    bool isCommon = false;
    Node* startCommonAddress = nullptr;

    CommonCheck checkCommon(Node* first, Node* second) {
        CommonCheck cc = CommonCheck();
        if(first->next != nullptr) {
           cc = checkCommon(first->next, second->next);
        }

        if(first == second) {
            cc.isCommon = true;
            cc.startCommonAddress = first;
            return cc;
        }

        return cc;
    }
};

int main() {
    Node* first;
    Node* second;
    Node* fOri = first;
    Node* sOri = second;

    // 多分だけど、どちらかが長い場合、その共通のノードは同じ長さになるまで出てこない
    int firstLength = 0;
    while(first->next) {
        first = first->next;
        firstLength++;
    }   
    int secondLength = 0;
    while(second->next) {
        second = second->next;
        secondLength++;
    }
    first = fOri;
    second = sOri;
    if (firstLength < secondLength) {
        for(int i = 0; i < secondLength - firstLength; ++i) {
            second = second->next;
        }
    } else if (secondLength < firstLength) {
        for(int i = 0; i < firstLength-secondLength; ++i) {
            first = first->next;
        }
    }

    CommonCheck cc = CommonCheck().checkCommon(first, second);
}