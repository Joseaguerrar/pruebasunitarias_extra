#include <gtest/gtest.h>
#include <sstream>
#include <calculadora.hh>
#include <algorithm>

bool ask_user(std::istream& in, std::ostream& out);

TEST(AskUserTest, ExitCommand) {
    std::stringstream input("salir\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_FALSE(result);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": Saliendo...\n");
}

TEST(AskUserTest, ValidExpression) {
    std::stringstream input("3 + 4\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_TRUE(result);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": El resultado es: 7\n");
}
TEST(AskUserTest, SpecialCharacters) {
    std::stringstream input("3 + 4 @ 5\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_TRUE(result);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": Error: Número mal formado: se encontró un caracter inválido\n");
}

TEST(AskUserTest, MultipleLines) {
    std::stringstream input("3 + 4\nsalir\n");
    std::stringstream output;

    bool result1 = ask_user(input, output);
    bool result2 = ask_user(input, output);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": El resultado es: 7\nIngrese una expresión o escriba \"salir\": Saliendo...\n");
}

TEST(AskUserTest, ExpresionCompleja) {
    std::stringstream input("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_TRUE(result);
    // Verificar el resultado esperado de la expresión compleja
    // Asegúrate de que el resultado sea correcto y ajusta el valor esperado según corresponda
}

TEST(AskUserTest, UpperAndLowerCase) {
    std::stringstream input("SALIR\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_FALSE(result);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": Saliendo...\n");
}

TEST(AskUserTest, ManejoDeExcepciones) {
    // Fuerza una excepción lanzando un carácter inválido
    std::stringstream input("3 + 4 @ 5\n");
    std::stringstream output;

    bool result = ask_user(input, output);

    EXPECT_TRUE(result);
    EXPECT_EQ(output.str(), "Ingrese una expresión o escriba \"salir\": Error: Número mal formado: se encontró un caracter inválido\n");
}
