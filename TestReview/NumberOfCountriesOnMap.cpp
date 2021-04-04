#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 隣接しているところの値が一緒であれば同一のものとみなし、それが何個あるかを返す。
 * - 基本的にはdpというか、すでに決定されているものをのぞいて上下左右を幅優先で探索していく？
 * - そこまでしなくても、各要素において上下左右を確認し、同じものが決定されていればそれ、
 * - そうでなければ自分に新しい値をつけるで良さそう。
 * - ダメだった。探索しないと見つけられない土地がある。
 */
int getCountriesMap(vector<vector<int> > A, int row, int columns) {
    vector<vector <int> > visit(row, vector<int>(columns,0));
    queue<pair<int,int> > q;
    int counter = 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (visit[i][j] != 0) continue;
            q.push(pair<int, int>(i,j));
            visit[i][j] = counter;
            while(!q.empty()) {
                pair<int, int> p = q.front();q.pop();
                if (p.first - 1 >= 0) {
                    if (A[p.first - 1][p.second] == A[p.first][p.second]) {
                        if (visit[p.first - 1][p.second] == 0) {
                            visit[p.first - 1][p.second] = counter;
                            q.push(pair<int,int>(p.first - 1, p.second));
                        }
                    }
                }
                if (p.first + 1 < row) {
                    if (A[p.first + 1][p.second] == A[p.first][p.second]) {
                        if (visit[p.first + 1][p.second] == 0) {
                            visit[p.first + 1][p.second] = counter;
                            q.push(pair<int,int>(p.first + 1, p.second));
                        }
                    }
                }

                if (p.second - 1 >= 0) {
                     if (A[p.first][p.second - 1] == A[p.first][p.second]) {
                        if (visit[p.first][p.second-1] == 0) {
                            visit[p.first][p.second - 1] = counter;
                            q.push(pair<int,int>(p.first, p.second - 1));
                        }
                    }                   
                }

                if (p.second + 1 < columns) {
                     if (A[p.first][p.second + 1] == A[p.first][p.second]) {
                         if (visit[p.first][p.second + 1] == 0) {
                            visit[p.first][p.second + 1] = counter;
                            q.push(pair<int,int>(p.first, p.second + 1));
                         }
                    }                   
                }
            }

            counter++;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << visit[i][j] << " ";
        }
        cout << endl;
    }
    
    return --counter;
}

vector<int> createRow(int list[], int size) {
    vector<int> v(size, 0);
    for (int i = 0; i < size; ++i) v[i] = list[i];
    return v;
}

int main() {
    vector<vector<int> > v;
    int list[] = {5,4,4};
    v.push_back(createRow(list,3));
    int list2[] = {4,3,4};
    v.push_back(createRow(list2,3));
    int list3[] = {3,2,4};
    v.push_back(createRow(list3,3));
    int list4[] = {2,2,2};
    v.push_back(createRow(list4,3));
    int list5[] = {3,3,4};
    v.push_back(createRow(list5,3));
    int list6[] = {1,4,4};
    v.push_back(createRow(list6,3));
    int list7[] = {4,1,1};
    v.push_back(createRow(list7,3));
    
    cout  << getCountriesMap(v, 7, 3) << endl;
    return 0;
}