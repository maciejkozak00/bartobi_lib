#ifndef BARTENDER_DRINK_H
#define BARTENDER_DRINK_H

#include <cstdint>
#include <map>
#include <string>

#include "../utils/Milliliters.h"
#include "Ingredient.h"

class Drink {
  std::map<Ingredient, Milliliters> drink_;
  std::string name_;

public:
  void setRecipe(const std::map<Ingredient, Milliliters>& recipe);
  const std::map<Ingredient, Milliliters>& getRecipe() const;
  const std::string& getName() const;
  void setName(const std::string& name);
};

#endif
