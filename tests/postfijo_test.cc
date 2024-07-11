#include <gtest/gtest.h>
#include <postfijo.hh>
#include <token.hh>

TEST(PostfijoTest, EvaluacionCorrecta) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 3));
    tokens.push(new TokenNumero(2, 3, 4));
    tokens.push(new TokenOperador(4, 5, '+'));

    Postfijo postfijo(tokens);
    EXPECT_TRUE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Resultado(), 7);
}

TEST(PostfijoTest, FaltanOperandos) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 10));
    tokens.push(new TokenOperador(2, 3, '+'));

    Postfijo postfijo(tokens);
    EXPECT_FALSE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Error(), "Error: faltan operandos");
}

TEST(PostfijoTest, SobranOperandos) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 10));
    tokens.push(new TokenNumero(2, 3, 5));
    tokens.push(new TokenNumero(4, 5, 2));
    tokens.push(new TokenOperador(6, 7, '+'));

    Postfijo postfijo(tokens);
    EXPECT_FALSE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Error(), "Error: sobran operandos");
}

TEST(PostfijoTest, MultiplicacionCorrecta) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 3));
    tokens.push(new TokenNumero(2, 3, 4));
    tokens.push(new TokenOperador(4, 5, '*'));

    Postfijo postfijo(tokens);
    EXPECT_TRUE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Resultado(), 12);
}

TEST(PostfijoTest, RestaCorrecta) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 10));
    tokens.push(new TokenNumero(2, 3, 4));
    tokens.push(new TokenOperador(4, 5, '-'));

    Postfijo postfijo(tokens);
    EXPECT_TRUE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Resultado(), 6);
}

TEST(PostfijoTest, DivisionCorrecta) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 8));
    tokens.push(new TokenNumero(2, 3, 2));
    tokens.push(new TokenOperador(4, 5, '/'));

    Postfijo postfijo(tokens);
    EXPECT_TRUE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Resultado(), 4);
}

TEST(PostfijoTest, DivisionPorCero) {
    std::queue<Token*> tokens;
    tokens.push(new TokenNumero(0, 1, 10));
    tokens.push(new TokenNumero(2, 3, 0));
    tokens.push(new TokenOperador(4, 5, '/'));

    Postfijo postfijo(tokens);
    EXPECT_FALSE(postfijo.IsValid());
    EXPECT_EQ(postfijo.Error(), "Error: división por cero");
}
