#include "SPS.h"
#include "DataConnector.h"

std::string key = "datafile.txt"; 
std::string value = "pass by value"; 
    
int SPS::registration() {
    DataConnector::readValue("test" + key, value);
    
    if("1" == value)
        return 1;
    
    return 0;
}