/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
    PasswordTest(){}
    virtual ~PasswordTest(){}
    virtual void SetUp(){}
    virtual void TearDown(){}
};

TEST(PasswordTest, mixed_case_simple)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("Password");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, all_lowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("password");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, all_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("PASSWORD");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, lowercase_then_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("passwordZ");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, uppercase_then_lowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("Zpassword");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, single_lowercase_letter)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("a");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, single_uppercase_letter)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("A");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, empty_password)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, numbers_and_symbols_with_mixed_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("123!aB$456");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, numbers_and_symbols_only)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("123!@#$456");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, leading_character_once)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Zebra");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeated_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaabc");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, entire_string_same_character)
{
    Password my_password;
    int actual = my_password.count_leading_characters("XXXXX");
    ASSERT_EQ(5, actual);
}

TEST(PasswordTest, case_sensitive_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaAaa");
    ASSERT_EQ(2, actual);
}

TEST(PasswordTest, symbol_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("!!!abc");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_string)
{
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, character_after_lowercase_range)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("{");
    ASSERT_FALSE(actual);
}