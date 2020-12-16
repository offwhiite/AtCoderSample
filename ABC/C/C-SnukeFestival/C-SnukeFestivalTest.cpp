#include "gtest/gtest.h"
#include "C-SnukeFestival.hpp"
TEST(getTypesSunuke, sample1) {
    vector<int> a = {1, 5};
    vector<int> b = {2, 4};
    vector<int> c = {3, 6};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 3);
}

TEST(getTypesSunuke, sample2) {
    vector<int> a = {1, 1, 1};
    vector<int> b = {2, 2, 2};
    vector<int> c = {3, 3, 3};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 27);
}


TEST(getTypesSunuke, sample3) {
    vector<int> a = {3, 14, 159, 2, 6, 53};
    vector<int> b = {58, 9, 79, 323, 84, 6};
    vector<int> c = {2643, 383, 2, 79, 50, 288};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 87);
}

TEST(getTypesSunuke, test1) {
    vector<int> a = {3, 3, 3, 3, 3, 3, 3};
    vector<int> b = {3, 3, 3, 3, 3, 3, 3};
    vector<int> c = {3, 3, 3, 3, 3, 3, 3};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}

TEST(getTypesSunuke, test2) {
    vector<int> a = {1, 1, 1, 1, 1, 1, 1};
    vector<int> b = {3, 3, 3, 3, 3, 3, 3};
    vector<int> c = {3, 3, 3, 3, 3, 3, 3};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}

TEST(getTypesSunuke, test3) {
    vector<int> a = {4, 4, 4, 4, 4, 4, 4};
    vector<int> b = {3, 3, 3, 3, 3, 3, 3};
    vector<int> c = {3, 3, 3, 3, 3, 3, 3};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}

TEST(getTypesSunuke, test4) {
    vector<int> a = {4, 4, 4, 4, 4, 4, 4};
    vector<int> b = {3, 3, 3, 3, 3, 3, 3};
    vector<int> c = {1, 1, 1, 1, 1, 1, 1};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}

TEST(getTypesSunuke, test5) {
    vector<int> a = {1, 1, 1, 1, 1, 1, 1};
    vector<int> b = {3, 3, 3, 3, 3, 3, 3};
    vector<int> c = {1, 1, 1, 1, 1, 1, 1};
    int ans = getTypesSunuke(a, b, c);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}