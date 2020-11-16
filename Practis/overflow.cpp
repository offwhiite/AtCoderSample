#include <iostream>
using namespace std;
 
int main(){
    cout << (100000 * 100000) << endl;
    int x=100000;
    cout << (x*x) << endl;
    long y=x*x;
    cout << y << endl;
    long z=x*(long)x;
    cout << z << endl;    
}