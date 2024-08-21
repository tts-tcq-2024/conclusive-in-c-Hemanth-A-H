#include <gtest/gtest.h>
#include "typewise-alert.h"

extern BreachType Mock_classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
extern BreachType  mock_breach;
extern BreachType (*Func_ptr_classifyTemperatureBreach)(CoolingType, double);

TEST(TypeWiseAlertTestSuite,Test_check_and_alter) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
BreachType expected_breach = TOO_LOW;
BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
checkAndAlert(TO_CONTROLLER,batteryChar,-10);
EXPECT_EQ(mock_breach,expected_breach);

}
