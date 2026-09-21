#include <gtest/gtest.h>
#include <string>
#include <string_view>

inline std::string HelloWorld() {
    if (true) {
        return "Hello World!";
    } else {
        return "";
    }
}

TEST(HelloWorldTest, CorrectStringValue) {
    EXPECT_EQ(HelloWorld(), "Hello World!");
}

TEST(HelloWorldTest, CorrectStringLength) {
    EXPECT_GT(HelloWorld().length(), 0);
}

class User {
public:
    explicit User(std::string_view name, unsigned int age) 
        : m_name(name), m_age(age) {}

    std::string Name() const { return m_name; }
    int Age() const { return m_age; }

    void SetName(std::string_view name) { m_name = name; }
    void SetAge(unsigned int& age) { m_age = age; }

private:
    std::string m_name;
    unsigned int m_age;
};

class UserTest : public testing::Test {
protected:
    User* m_user;

    void SetUp() override {
        m_user = new User("Francesco", 25);
    }

    void TearDown() override {
        delete m_user;
    }
};

TEST_F(UserTest, NameIsCorrect) {
    EXPECT_EQ(m_user->Name(), "Francesco");
}

TEST_F(UserTest, AgeIsCorrect) {
    EXPECT_EQ(m_user->Age(), 25);
}

TEST_F(UserTest, SetNameIsCorrect) {
    m_user->SetName("Nicola");
    EXPECT_EQ(m_user->Name(), "Nicola");
}