#include "gtest/gtest.h"
#include "base.h"

TEST(baseTest, test1) {
    EXPECT_EQ (base::method(0),  0);
}
