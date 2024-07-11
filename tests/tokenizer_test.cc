
#include <gtest/gtest.h>
#include <tokenizer.hh>

TEST(TokenizerTest, EmptyString) {
    Tokenizer tokenizer("");
    EXPECT_FALSE(tokenizer.HasNext());
    EXPECT_EQ(tokenizer.Next(), nullptr);
}

TEST(TokenizerTest, EspacioEnBlanco) {
    Tokenizer tokenizer("+ -");
    const char* operadores[] = { "+", "-"};
    for (int i = 0; i < 2; ++i) {
        EXPECT_TRUE(tokenizer.HasNext());
        Token* token = tokenizer.Next();
        TokenOperador* operador = dynamic_cast<TokenOperador*>(token);
        char operador_esperado = operadores[i][0];
        EXPECT_EQ(operador->operador(), operador_esperado);
    }
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, ErrorDecimal) {
    Tokenizer tokenizer("2..0");
    EXPECT_THROW(tokenizer.Next(), std::runtime_error);
}

TEST(TokenizerTest, NumeroInvalido) {
    Tokenizer tokenizer("2D");
    EXPECT_TRUE(tokenizer.Next());
    EXPECT_THROW(tokenizer.Next(), std::runtime_error);
}

TEST(TokenizerTest, NumeroDecimal) {
    Tokenizer tokenizer("2D");
    EXPECT_TRUE(tokenizer.Next());
    EXPECT_THROW(tokenizer.Next(), std::runtime_error);
}

TEST(TokenizerTest, DecimalGrande) {
    Tokenizer tokenizer("2.005");
    Token* token = tokenizer.Next();
    TokenNumero* numero = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(numero->valor(), 2.005);
}

TEST(TokenizerTest, TokenizeNumeros) {
    Tokenizer tokenizer("123 456");
    Token* token1 = tokenizer.Next();
    TokenNumero* numToken1 = dynamic_cast<TokenNumero*>(token1);
    ASSERT_NE(numToken1, nullptr);
    EXPECT_EQ(numToken1->valor(), 123);

    Token* token2 = tokenizer.Next();
    TokenNumero* numToken2 = dynamic_cast<TokenNumero*>(token2);
    ASSERT_NE(numToken2, nullptr);
    EXPECT_EQ(numToken2->valor(), 456);

    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeOperadorSum) {
    Tokenizer tokenizer("+");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_EQ(opToken->operador(), '+');
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeOperadorMenos) {
    Tokenizer tokenizer("-");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_EQ(opToken->operador(), '-');
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeOperadorMult) {
    Tokenizer tokenizer("*");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_EQ(opToken->operador(), '*');
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeOperadorDiv) {
    Tokenizer tokenizer("/");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_EQ(opToken->operador(), '/');
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeParenIzq) {
    Tokenizer tokenizer("(");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_TRUE(opToken->IsLeftParenthesis());
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, TokenizeParenDer) {
    Tokenizer tokenizer(")");
    Token* token = tokenizer.Next();
    TokenOperador* opToken = dynamic_cast<TokenOperador*>(token);
    ASSERT_NE(opToken, nullptr);
    EXPECT_TRUE(opToken->IsRightParenthesis());
    EXPECT_FALSE(tokenizer.HasNext());
}

TEST(TokenizerTest, Numeroinvalido) {
    Tokenizer tokenizer("123.45.67");
    EXPECT_THROW(tokenizer.Next(), std::runtime_error);
}


