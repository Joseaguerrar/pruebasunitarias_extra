#include <gtest/gtest.h>

#include <calculadora.hh>

TEST(CalculadoraTest, EmptyExpression) {
    Calculadora calculadora("");
    EXPECT_TRUE(calculadora.IsValid());
    EXPECT_EQ(calculadora.Resultado(), 0);
}