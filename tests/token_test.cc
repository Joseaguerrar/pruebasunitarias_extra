#include <gtest/gtest.h>
#include <token.hh>

TEST(TokenTest, InicioyFin) {
    TokenNumero token('0','1', 8);
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_FALSE(token.IsOperator());
}

TEST(TokenTest, operadorMult) {
    TokenOperador token('0','1', '*');
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_TRUE(token.IsOperator());
    EXPECT_EQ(token.GetPrecedence(), 3);
}

TEST(TokenTest, operadorSuma) {
    TokenOperador token('0','1', '+');
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_TRUE(token.IsOperator());
    EXPECT_EQ(token.GetPrecedence(), 1);
}

TEST(TokenTest, operadorResta) {
    TokenOperador token('0','1', '-');
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_TRUE(token.IsOperator());
    EXPECT_EQ(token.GetPrecedence(), 1);
}

TEST(TokenTest, operadorVacio) {
    TokenOperador token('0','1', ' ');
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_TRUE(token.IsOperator());
    EXPECT_EQ(token.GetPrecedence(), 0);
}

TEST(TokenTest, operadorDivision) {
    TokenOperador token('0','1', '/');
    EXPECT_EQ(token.inicio(), '0');
    EXPECT_EQ(token.fin(), '1');
    EXPECT_TRUE(token.IsOperator());
    EXPECT_EQ(token.GetPrecedence(), 2);
}



