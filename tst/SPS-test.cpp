#include "gtest/gtest.h"
#include "SPS.h"

TEST(SPSTest, test1) {
    EXPECT_EQ (SPS::registration(),  0);
}
