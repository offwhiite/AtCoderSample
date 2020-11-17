#include "gtest/gtest.h"
#include "binarySearch.hpp"


int getCount(vector<long> s, vector<long> t) {
    int count = 0;
    for (int i = 0;i < (int)t.size(); ++i) {
        if (binary_search(t[i], s) != -1) {
            count++;
        }
    }
    return count;
}

TEST(multipleOfThreeDigit, sample1) {
    int n = 5;
    int q = 3;
    vector<long> s = {1, 2, 3, 4, 5};
    vector<long> t = {3,4,1};

    int count = getCount(s,t);
    ASSERT_TRUE(count == 3);
}

TEST(multipleOfThreeDigit, sample2) {
    int n = 3;
    int q = 1;
    vector<long> s = {1, 2, 3};
    vector<long> t = {5};

    int count = getCount(s,t);
    ASSERT_TRUE(count == 0);
}

TEST(multipleOfThreeDigit, sample3) {
    int n = 5;
    int q = 2;
    vector<long> s = {1, 1, 2, 2, 3};
    vector<long> t = {1,2};

    int count = getCount(s,t);
    ASSERT_TRUE(count == 2);
}
