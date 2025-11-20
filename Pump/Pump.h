#ifndef PUMP_IPUMP_H
#define PUMP_IPUMP_H

#include "../Bartender/Drink.h"
#include "../utils/Milliliters.h"

#include <cstdint>

class IPump {
public:
  virtual bool isPumping() = 0;
  virtual void setPin(uint8_t pin) { pin_ = pin; }
  virtual uint8_t getPin() { return pin_; }
  virtual void setFlowRate(Milliliters flowRate) { flowRate_ = flowRate; }
  virtual Milliliters getFlowRate() { return flowRate_; }
  virtual void turnOnPump() = 0;
  virtual void turnOffPump() = 0;

  virtual ~IPump() = default;
  IPump() : pin_(0), flowRate_(Milliliters(1.5)), isPumping_(false) {}

protected:
  uint8_t pin_;
  Milliliters flowRate_;
  bool isPumping_;
};

class PumpStub : public IPump {
public:
  PumpStub() : IPump() {
    turnOffPump();
  }
  bool isPumping() override;
  void turnOnPump() override;
  void turnOffPump() override;
};

#endif // PUMP_IPUMP_H