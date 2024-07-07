
#include <gtest/gtest.h>

#include <tokenizer.hh>

TEST(TokenizerTest, EmptyString) {
    Tokenizer tokenizer("");
    EXPECT_FALSE(tokenizer.HasNext());
}