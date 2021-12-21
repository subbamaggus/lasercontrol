#include "gtest/gtest.h"
#include "Bluhmware.h"

//TEST_F(BluhmwareTest, test1) {    
//    EXPECT_EQ (bw->getLaser(),  -1);
//    bw.setLaser(12);
//    EXPECT_EQ (bw.getLaser(),  12);
//}

TEST(BluhmwareTest, test1) {
    Bluhmware bw;    
    EXPECT_EQ (bw.getLaser(),  -1);
    bw.setLaser(12);
    EXPECT_EQ (bw.getLaser(),  12);
}
