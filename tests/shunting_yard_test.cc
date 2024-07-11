#include <gtest/gtest.h>

#include <shunting_yard.hh>

class MockTokenizer : public ITokenizer {
   private:
    std::queue<Token*> tokens;

   public:
    MockTokenizer(const std::vector<Token*>& tokens) {
        for (auto token : tokens) {
            this->tokens.push(token);
        }
    }

    virtual bool HasNext() const override { return !tokens.empty(); }

    virtual Token* Next() override {
        Token* token = tokens.front();
        tokens.pop();
        return token;
    }
};

TEST(ShuntingYardTest, EmptyExpression) {
    MockTokenizer tokenizer({});
    ShuntingYard shunting_yard(tokenizer);
    std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();
    EXPECT_TRUE(postfijo.empty());
}

TEST(ShuntingYardTest, EvaluarSuma) {
    std::vector<Token*> tokens = {
        new TokenNumero(0, 1, 2.0),      
        new TokenOperador(1, 2, '+'),
        new TokenNumero(2, 3, 3.0) 
    };
    MockTokenizer tokenizer(tokens);
    ShuntingYard shunting_yard(tokenizer);
    std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();
    Token* token = postfijo.front();
    postfijo.pop();
    TokenNumero* num = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(num->valor(), 2.0);
    token = postfijo.front();
    postfijo.pop();
    num = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(num->valor(), 3.0);
    token = postfijo.front();
    postfijo.pop();
    TokenOperador* op = dynamic_cast<TokenOperador*>(token);
    EXPECT_EQ(op->operador(), '+');
    EXPECT_TRUE(postfijo.empty());
}

TEST(ShuntingYardTest, PrecedenciaMayor) {
    std::vector<Token*> tokens = {
        new TokenNumero(0, 1, 1.0),       
        new TokenOperador(1, 2, '+'),     
        new TokenNumero(2, 3, 2.0),       
        new TokenOperador(3, 4, '*'),     
        new TokenNumero(4, 5, 5.0)       
    };
    MockTokenizer tokenizer(tokens);
    ShuntingYard shunting_yard(tokenizer);
    std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();
    Token* token = postfijo.front();
    postfijo.pop();
    TokenNumero* num = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(num->valor(), 1.0);
    token = postfijo.front();
    postfijo.pop();
    num = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(num->valor(), 2.0);
    token = postfijo.front();
    postfijo.pop();
    num = dynamic_cast<TokenNumero*>(token);
    EXPECT_EQ(num->valor(), 5.0);
    token = postfijo.front();
    postfijo.pop();
    TokenOperador* op = dynamic_cast<TokenOperador*>(token);
    EXPECT_EQ(op->operador(), '*');
    token = postfijo.front();
    postfijo.pop();
    op = dynamic_cast<TokenOperador*>(token);
    EXPECT_EQ(op->operador(), '+');
    EXPECT_TRUE(postfijo.empty());
}

TEST(ShuntingYardTest, ErrorParentesisDerecho) {
    std::vector<Token*> tokens = {
        new TokenNumero(0, 1, 1.0),       
        new TokenOperador(1, 2, '+'),     
        new TokenNumero(2, 3, 2.0),       
        new TokenOperador(3, 4, ')')      
    };
    MockTokenizer tokenizer(tokens);
    ShuntingYard shunting_yard(tokenizer);
    EXPECT_THROW({std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();}, std::runtime_error);
}

TEST(ShuntingYardTest, ErrorParentesisIzquierdo) {
    std::vector<Token*> tokens = {
        new TokenNumero(0, 1, 1.0),       
        new TokenOperador(1, 2, '+'),     
        new TokenNumero(2, 3, 2.0),       
        new TokenOperador(3, 4, '(')      
    };
    MockTokenizer tokenizer(tokens);
    ShuntingYard shunting_yard(tokenizer);
    EXPECT_THROW({std::queue<Token*> postfijo = shunting_yard.ConvertirAPostfijo();}, std::runtime_error);
}