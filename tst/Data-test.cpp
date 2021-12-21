#include "gtest/gtest.h"
#include "Data.h"

TEST(DataTest, test1) {
    EXPECT_EQ (Data::method("12345"),  0);
}
