#include <gtest/gtest.h>
#include <string>

std::string HelloWorld() {
    return "Hello World!";
}

TEST(HelloWorldTest, SalutoCorretto) {
    EXPECT_EQ(HelloWorld(), "Hello World!");
}

TEST(HelloWorldTest, LunghezzaStringa) {
    EXPECT_GT(HelloWorld().length(), 0);
}