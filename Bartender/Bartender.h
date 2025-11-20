#ifndef BARTENDER_BARTENDER_H
#define BARTENDER_BARTENDER_H

#include "Drink.h"
#include <vector>

class Bartender {
public:
  static Bartender& getInstance() {
    static Bartender instance;
    return instance;
  }

  void init();
  void prepareDrink(Drink drink);
  std::vector<Drink> getDrinks();

private:
  std::vector<Drink> drinks_;

  Bartender() = default;
  ~Bartender() = default;

  Bartender(const Bartender&) = delete;
  Bartender& operator=(const Bartender&) = delete;
  Bartender(Bartender&&) = delete;
  Bartender& operator=(Bartender&&) = delete;
};

#endif
