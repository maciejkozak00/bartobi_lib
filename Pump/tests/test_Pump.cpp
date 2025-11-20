#include "../Pump.h"

#include <gtest/gtest.h>

class PumpTestFixture : public ::testing::Test {
protected:
  PumpStub pump;
};

TEST_F(PumpTestFixture, InitialState) { EXPECT_FALSE(pump.isPumping()); }

TEST_F(PumpTestFixture, TurnOnPump) {
  pump.turnOnPump();
  EXPECT_TRUE(pump.isPumping());
}

TEST_F(PumpTestFixture, TurnOffPump) {
  pump.turnOnPump();
  pump.turnOffPump();
  EXPECT_FALSE(pump.isPumping());
}

TEST_F(PumpTestFixture, SetAndGetPin) {
  uint8_t testPin = 5;
  pump.setPin(testPin);
  EXPECT_EQ(pump.getPin(), testPin);
}

TEST_F(PumpTestFixture, SetAndGetFlowRate) {
  auto testFlowRate{150_ml};
  pump.setFlowRate(testFlowRate);
  EXPECT_EQ(pump.getFlowRate().value_, testFlowRate.value_);
}
