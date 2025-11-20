#include "Drink.h"

void Drink::setRecipe(const std::map<Ingredient, Milliliters>& recipe) {
  drink_ = recipe;
}

const std::map<Ingredient, Milliliters>& Drink::getRecipe() const {
  return drink_;
}

const std::string& Drink::getName() const { return name_; }

void Drink::setName(const std::string& name) { name_ = name; }
