#ifndef BARTENDER_DRINKBUILDER_H
#define BARTENDER_DRINKBUILDER_H

#include "Drink.h"
#include "Ingredient.h"
#include <map>
#include <string>

class DrinkBuilder {
public:
  static DrinkBuilder& getInstance() {
    static DrinkBuilder instance;
    return instance;
  }
  DrinkBuilder& addIngredient(const Ingredient ingredient, const Milliliters amount);
  DrinkBuilder& setName(const std::string& name);
  Drink build();
  void reset();

private:
  std::map<Ingredient, Milliliters> recipe_;
  std::string name_;

  DrinkBuilder() = default;
  ~DrinkBuilder() = default;
  DrinkBuilder(const DrinkBuilder&) = delete;
  DrinkBuilder& operator=(const DrinkBuilder&) = delete;
};

#endif
