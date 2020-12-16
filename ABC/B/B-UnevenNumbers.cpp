#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int N=0;
    cin >> N;

    int count = 0;
    for (int i=1;i <= N;i++) {
        if(to_string(i).length() % 2 != 0) count++;
    }

    cout << count << endl;
}