#include "gtest/gtest.h"
#include "DataConnector.h"

TEST(DataConnectorTest, test_opc) {
    //arrange
    //act
    //assert
    std::string key = "ns=3;s=Local Items.pdv_tok_vorfertigung.pdv_to_vf_w2"; 
    std::string value = "pass by value"; 
    
    DataConnector myDataConnector;
    myDataConnector.useOPC = true;
    
    EXPECT_EQ (myDataConnector.readValue (key, value),  0);
    myDataConnector.readValue (key, value);
    EXPECT_EQ (value,  "uiuiui");
}


TEST(DataConnectorTest, test_file) {
    std::string key = "datafiletest.txt"; 
    std::string value = "pass by value"; 
    
    DataConnector myDataConnector;
    myDataConnector.useOPC = false;
    
    EXPECT_EQ (myDataConnector.readValue (key, value),  0);
    myDataConnector.readValue (key, value);
    EXPECT_EQ (value,  "uiuiui");
}

