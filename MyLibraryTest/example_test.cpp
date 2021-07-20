#include <gtest/gtest.h>
#include <example.h>

TEST(ExampleTest, BasicAssertions) {

    EXPECT_EQ("hello", Example::getHello());

    EXPECT_EQ(7 * 6, 42);

}

