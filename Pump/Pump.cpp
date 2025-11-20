#include "Pump.h"

bool PumpStub::isPumping() { return isPumping_; }

void PumpStub::turnOnPump() { isPumping_ = true; }

void PumpStub::turnOffPump() { isPumping_ = false; }
