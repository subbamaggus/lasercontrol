#include "gtest/gtest.h"
#include "SPS.h"

TEST(SPSTest, test1) {
    SPS mySPS;
    
    EXPECT_EQ (mySPS.registration(),  0);
}
