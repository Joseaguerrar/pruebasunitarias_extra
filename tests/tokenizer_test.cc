
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



