#include <gtest/gtest.h>

#include <calculadora.hh>

TEST(CalculadoraTest, EmptyExpression) {
    Calculadora calculadora("");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 0);
}

TEST(CalculadoraTest, suma) {
    Calculadora calculadora("5+3");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 8);
}

TEST(CalculadoraTest, resta) {
    Calculadora calculadora("5-3");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 2);
}

TEST(CalculadoraTest, multiplicacion) {
    Calculadora calculadora("5*3");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 15);
}

TEST(CalculadoraTest, divisionNormal) {
    Calculadora calculadora("10/2");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 5);
}
TEST(CalculadoraTest, divisionPorCero) {
    Calculadora calculadora("5/0");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 0);
}