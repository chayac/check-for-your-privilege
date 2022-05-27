#include "gtest/gtest.h"
#include "model.h"

TEST(ModelTests, testModel) {
    ASSERT_STREQ("Hello Jim", generateHelloString("Jim").c_str());
}