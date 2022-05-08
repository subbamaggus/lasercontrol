#include "gtest/gtest.h"
#include "Data.h"

TEST(DataTest, test1) {
    //EXPECT_EQ (myData.method("12345"),  0);

    Data myData;
    std::string snr = "";
    EXPECT_EQ (myData.number2formatted(1, snr),  0);
    EXPECT_EQ (snr,  "0001");

    EXPECT_EQ (myData.number2formatted(35, snr),  0);
    EXPECT_EQ (snr,  "000z");

    int snr_i = 0;
    EXPECT_EQ (myData.formatted2number("0001", snr_i),  0);
    EXPECT_EQ (snr_i,  1);
    
    EXPECT_EQ (myData.formatted2number("0002", snr_i),  0);
    EXPECT_EQ (snr_i,  2);
    
    EXPECT_EQ (myData.formatted2number("0010", snr_i),  0);
    EXPECT_EQ (snr_i,  36);

    EXPECT_EQ (myData.formatted2number("000z", snr_i),  0);
    EXPECT_EQ (snr_i,  35);
}

TEST(DBTest, test2) {
    Data myData;
    EXPECT_EQ (myData.isConnected(), false);
    EXPECT_EQ (myData.connect(), 0);
    EXPECT_EQ (myData.isConnected(), true);
}
