#include "../Drink.h"
#include <gtest/gtest.h>

class DrinkTestFixture : public ::testing::Test {
protected:
  Drink drink;
  void SetUp() override {}
  void TearDown() override {}
};

TEST_F(DrinkTestFixture, SetRecipe_empty) {
  std::map<Ingredient, Milliliters> recipe = {};
  drink.setRecipe(recipe);
  EXPECT_TRUE(drink.getRecipe().empty());
}

TEST_F(DrinkTestFixture, SetRecipe_oneIngredient) {
  std::map<Ingredient, Milliliters> recipe = {
      {Ingredient::VODKA, 50_ml},
  };
  drink.setRecipe(recipe);
  EXPECT_EQ(drink.getRecipe().at(Ingredient::VODKA).value_, 50);
}

TEST_F(DrinkTestFixture, SetRecipe_multipleIngredients) {
  std::map<Ingredient, Milliliters> recipe = {
      {Ingredient::VODKA, 50_ml},
      {Ingredient::ORANGE_JUICE, 100_ml},
      {Ingredient::COLA, 150_ml},
  };
  drink.setRecipe(recipe);
  EXPECT_EQ(drink.getRecipe().at(Ingredient::VODKA).value_, 50);
  EXPECT_EQ(drink.getRecipe().at(Ingredient::ORANGE_JUICE).value_, 100);
  EXPECT_EQ(drink.getRecipe().at(Ingredient::COLA).value_, 150);
}

TEST_F(DrinkTestFixture, SetName) {
  drink.setName("dupa");
  EXPECT_EQ(drink.getName(), "dupa");
}

TEST_F(DrinkTestFixture, SetName_empty) {
  drink.setName("");
  EXPECT_EQ(drink.getName(), "");
}

TEST_F(DrinkTestFixture, DrinkCreated) {
  drink.setName("Screwdriver");
    std::map<Ingredient, Milliliters> recipe = {
        {Ingredient::VODKA, 50_ml},
        {Ingredient::ORANGE_JUICE, 100_ml},
    };
    drink.setRecipe(recipe);
    EXPECT_EQ(drink.getName(), "Screwdriver");
    EXPECT_EQ(drink.getRecipe().at(Ingredient::VODKA).value_, 50);
    EXPECT_EQ(drink.getRecipe().at(Ingredient::ORANGE_JUICE).value_, 100);
}
