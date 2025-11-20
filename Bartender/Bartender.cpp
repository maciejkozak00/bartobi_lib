#include "Bartender.h"
#include "DrinkBuilder.h"

void Bartender::init() {
  auto& drinkBuilder = DrinkBuilder::getInstance();
  auto drink = drinkBuilder.addIngredient(Ingredient::VODKA, 50_ml)
                   .addIngredient(Ingredient::ORANGE_JUICE, 100_ml)
                   .setName("Screwdriver")
                   .build();
  drinks_.push_back(drink);
}

std::vector<Drink> Bartender::getDrinks() {
  return drinks_;
}

void Bartender::prepareDrink(Drink drink) {}
