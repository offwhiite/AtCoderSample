#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

class Point {
    public:
    double x;
    double y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

int main() {
    int N;
    cin >> N; // 街の数

    vector<Point> points(N, Point());
    for (int i = 0; i < N; ++i) {
        double x,y;
        cin >> x >> y;
        points[i] = Point(x,y);
    }
    
    double total = 0;
    long count = 0;
    vector<int> v(N);
    for(int i = 0;i < N; i++) {
        v[i] = i;
    }
    do {
        double routeDistance = 0;
        for (int i = 0; i < N-1; ++i) {
            double x = points[v[i]].x - points[v[i+1]].x;
            double y = points[v[i]].y - points[v[i+1]].y;

            double dis = (x*x) + (y*y);
            double distance = pow((x*x) + (y*y), 0.5);
            routeDistance += distance;
        }
        total += routeDistance;
        count++;
    } while (next_permutation(v.begin(), v.end()));

    double average = total / count;
    cout  << fixed << setprecision(10) << average << endl;
    return 0;
}