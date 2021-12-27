#include "gtest/gtest.h"
#include "Data.h"

TEST(DataTest, test1) {
    //EXPECT_EQ (Data::method("12345"),  0);
//    std::string snr = "";
//    EXPECT_EQ (Data::number2formatted(1, snr),  0);
//    EXPECT_EQ (snr,  "0001");

    int snr_i = 0;
    EXPECT_EQ (Data::formatted2number("0001", snr_i),  0);
    EXPECT_EQ (snr_i,  1);
    
    EXPECT_EQ (Data::formatted2number("0002", snr_i),  0);
    EXPECT_EQ (snr_i,  2);
    
    EXPECT_EQ (Data::formatted2number("0010", snr_i),  0);
    EXPECT_EQ (snr_i,  36);

    EXPECT_EQ (Data::formatted2number("000z", snr_i),  0);
    EXPECT_EQ (snr_i,  35);
    
}
