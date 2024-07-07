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