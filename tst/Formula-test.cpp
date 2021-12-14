#include "gtest/gtest.h"
#include "Formula.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (Formula::bla (0),  0);
    EXPECT_EQ (Formula::bla (10), 30);
    EXPECT_EQ (Formula::bla (50), 150);
}

TEST(maggusTest, test2) {
    EXPECT_EQ (Formula::maggus (1,1), 2);    
}