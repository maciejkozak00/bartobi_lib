#include "../Bartender.h"
#include <gtest/gtest.h>

class BartenderTestFixture : public ::testing::Test {
protected:
  Bartender& bartender = Bartender::getInstance();
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(BartenderTestFixture, InitDoesNotThrow) {
  EXPECT_NO_THROW(bartender.init());
}

TEST_F(BartenderTestFixture, initAddsDrink) {
    bartender.init();
    auto drinks = bartender.getDrinks();
    EXPECT_EQ(drinks.size(), 1);
    EXPECT_EQ(drinks[0].getName(), "Screwdriver");
    EXPECT_EQ(drinks[0].getRecipe().at(Ingredient::VODKA).value_, 50);
    EXPECT_EQ(drinks[0].getRecipe().at(Ingredient::ORANGE_JUICE).value_, 100);
}
