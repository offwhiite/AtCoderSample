#include "gtest/gtest.h"
#include "B-GoToJail.h"
TEST(isDoubletThreeOrMore, sample1) {
    int N = 5;
    vector<vector<int> > v(N, vector<int>(2,0));
    v[0] = {1, 1};
    v[1] = {6, 6};
    v[2] = {4, 4};
    v[3] = {3, 3};
    v[4] = {3, 2};
    ASSERT_TRUE(isDoubletThreeOrMore(v));
}

TEST(isDoubletThreeOrMore, sample2) {
    int N = 5;
    vector<vector<int> > v(N, vector<int>(2,0));
    v[0] = {1, 1};
    v[1] = {2, 2};
    v[2] = {3, 2};
    v[3] = {4, 4};
    v[4] = {5, 5};
    ASSERT_FALSE(isDoubletThreeOrMore(v));
}