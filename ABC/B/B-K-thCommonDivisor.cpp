#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[]) {
    int A,B,K = 0;
    cin >> A >> B >> K;

    int max = A;
    if (A < B) max = B;  

    int count = 0;
    vector<int> v;
    v.assign(max, 0);
    for (int i=max;i>0;i--) {
        if (A%i==0 && B%i==0) {
            v[count] = i;
            count++;
        }
    }
    cout << v[K-1] << endl;  
    return 0;
}