#include "gtest/gtest.h"
#include "DataConnector.h"

TEST(DataConnectorTest, test1) {
    //arrange
    //act
    //assert
    std::string key = "ns=3;s=Local Items.pdv_tok_vorfertigung.pdv_to_vf_w2"; 
    std::string value = "pass by value"; 
    
    EXPECT_EQ (DataConnector::readValue (key, value),  0);
    DataConnector::readValue (key, value);
    EXPECT_EQ (value,  "uiuiui");
}

