#include "gtest/gtest.h"
#include "C-To3.hpp"
TEST(multipleOfThreeDigit, sample1) {
    string N = "35";
    ASSERT_TRUE(multipleOfThreeDigit(N) == 1);
}

TEST(multipleOfThreeDigit, sample2) {
    string N = "369";
    ASSERT_TRUE(multipleOfThreeDigit(N) == 0);
}

TEST(multipleOfThreeDigit, sample3) {
    string N = "6227384";
    ASSERT_TRUE(multipleOfThreeDigit(N) == 1);
}

TEST(multipleOfThreeDigit, sample4) {
    string N = "11";
    ASSERT_TRUE(multipleOfThreeDigit(N) == -1);
}


TEST(multipleOfThreeDigit, boundaryValueMax) {
    string N = "99999999999999999";
    int ans = multipleOfThreeDigit(N);
    cout << ans << endl;
    ASSERT_TRUE(ans == 0);
}

TEST(multipleOfThreeDigit, boundaryValueMIN) {
    string N = "1";
    int ans = multipleOfThreeDigit(N);
    cout << ans << endl;
    ASSERT_TRUE(ans == -1);
}