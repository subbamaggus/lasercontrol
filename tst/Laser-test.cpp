#include "gtest/gtest.h"
#include "Laser.h"

TEST(LaserTest, test1) {
    EXPECT_EQ (Laser::mark(),  0);
}
