#include <gtest/gtest.h>
#include "typewise-alert.h"

extern BreachType Mock_classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
extern BreachType  mock_breach;

TEST(TypeWiseAlertTestSuite,Test_check_and_alter) {
Func_ptr_classifyTemperatureBreach = Mock_classifyTemperatureBreach;
checkAndAlert(TO_CONTROLLER,PASSIVE_COOLING,-10)
EXPECT_EQ(mock_breach,LOW);

}
