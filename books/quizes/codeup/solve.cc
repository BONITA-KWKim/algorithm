#include "gtest/gtest.h"

#include "answer-1916.hpp"
#include "answer-3701.hpp"
#include "answer-3733.hpp"

TEST (CODEUP, NO_1916)
{
    Answer1916 *answer = new Answer1916();
    int result = 0;

    result = answer->solution(7);
    EXPECT_EQ(13, result);
    result = answer->solution(151);
    EXPECT_EQ(3081, result);
}

TEST (CODEUP, NO_3701)
{
    Answer3701 *answer = new Answer3701();
    int result = 0;

    result = answer->get_triangle(3, 2);
    EXPECT_EQ(3, result);
}

TEST (CODEUP, NO_3733)
{
    Answer3733 *answer = new Answer3733();
    int result = 0;

    answer->solution(1, 10);
    std::cout << answer->collaz_length[0].no << answer->collaz_length[0].length << std::endl;

    EXPECT_EQ(3, 3);
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
