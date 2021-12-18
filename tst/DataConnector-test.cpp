#include "gtest/gtest.h"
#include "DataConnector.h"

TEST(DataConnectorTest, test1) {
    //arrange
    //act
    //assert
    std::string key = "datafiletest.txt"; 
    std::string value = "pass by value"; 
    
    EXPECT_EQ (DataConnector::readValue (key, value),  0);
    DataConnector::readValue (key, value);
    EXPECT_EQ (value,  "uiuiui");
}

