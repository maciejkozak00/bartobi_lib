#include <gtest/gtest.h>
#include "../DrinkBuilder.h"
#include "../Ingredient.h"

class DrinkBuilderTestFixture : public ::testing::Test
{
protected:
    DrinkBuilder& builder = DrinkBuilder::getInstance();

    void SetUp() override
    {
        builder.reset();
    }

    void TearDown() override
    {
        builder.reset();
    }
};

TEST_F(DrinkBuilderTestFixture, EmptyDrink)
{
    Drink drink = builder.build();
    auto recipe = drink.getRecipe();
    ASSERT_EQ(recipe.size(), 0);
    EXPECT_TRUE(drink.getName().empty());
}

TEST_F(DrinkBuilderTestFixture, AddSingleIngredient)
{
    builder.addIngredient(Ingredient::VODKA, Milliliters(50));
    Drink drink = builder.build();
    auto recipe = drink.getRecipe();
    ASSERT_EQ(recipe.size(), 1);
    EXPECT_EQ(recipe.at(Ingredient::VODKA).value_, 50u);
}

TEST_F(DrinkBuilderTestFixture, AddMultipleIngredients)
{
    builder.addIngredient(Ingredient::VODKA, Milliliters(50));
    builder.addIngredient(Ingredient::COLA, Milliliters(100));
    Drink drink = builder.build();
    auto recipe = drink.getRecipe();
    ASSERT_EQ(recipe.size(), 2);
    EXPECT_EQ(recipe.at(Ingredient::VODKA).value_, 50u);
    EXPECT_EQ(recipe.at(Ingredient::COLA).value_, 100u);
}

TEST_F(DrinkBuilderTestFixture, SetDrinkName)
{
    builder.setName("TestDrink");
    Drink drink = builder.build();
    EXPECT_EQ(drink.getName(), "TestDrink");
}

TEST_F(DrinkBuilderTestFixture, ResetClearsBuilder)
{
    builder.addIngredient(Ingredient::VODKA, Milliliters(50));
    builder.setName("TestDrink");
    builder.reset();
    Drink drink = builder.build();
    EXPECT_TRUE(drink.getRecipe().empty());
    EXPECT_EQ(drink.getName(), "");
}