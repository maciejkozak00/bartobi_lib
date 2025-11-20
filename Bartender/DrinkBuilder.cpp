#include "DrinkBuilder.h"

DrinkBuilder& DrinkBuilder::addIngredient(const Ingredient ingredient,
                                          const Milliliters amount) {
  recipe_.insert_or_assign(ingredient, amount);
  return *this;
}

DrinkBuilder& DrinkBuilder::setName(const std::string& name) {
  name_ = name;
  return *this;
}

Drink DrinkBuilder::build() {
  Drink drink;
  drink.setRecipe(recipe_);
  drink.setName(name_);
  return drink;
}

void DrinkBuilder::reset() {
  recipe_.clear();
  name_.clear();
}
