#include "DataConnector.h"
#include "DataFileConnector.h"
#include "DataOPCConnector.h"

#include "easylogging++.h"

#include <string> // for string class
#include <fstream>

//std::string folder = "data/";
bool useOPC = false;

int DataConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "readValue: " << key;

    if(useOPC) {
        DataOPCConnector::readValue (key, value);
        
        LOG(INFO) << "returning: " << value;

        return 0;
    }
    DataFileConnector::readValue (key, value);

    LOG(INFO) << "returning: " << value;

    return 0;
}

int DataConnector::writeValue(std::string key, std::string value) {
    LOG(INFO) << "writeValue: " << key << ", " << value;

    if(useOPC) {
        DataOPCConnector::writeValue (key, value);

        return 0;
    }
    
    DataConnector::writeValue (key, value);

    return 0;
}