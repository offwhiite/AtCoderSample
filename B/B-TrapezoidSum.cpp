#include <iostream>
#include <vector>
using namespace std;
class Point {
    public:
    int a;
    int b;

    Point() {
        a = 0;
        b = 0;
    }
    Point(int _a, int _b) {
        a = _a;
        b = _b;
    }
};

int main() {
    int N;
    cin >> N;

    vector<Point> points(N, Point());
    for (int i = 0;i < N; ++i) {
        int a,b;
        cin >> a >> b;
        points[i] = Point(a,b);
    }

    long ans = 0;
    for (int i = 0; i < N; ++i) {
        long bAns = 0.5 * points[i].b * (points[i].b + 1);
        long aAns = 0.5 * points[i].a * (points[i].a + 1);

        ans += (bAns - aAns) + points[i].a;
    }

    cout << ans << endl;

    return 0;
}