#include "DataConnector.h"
#include "DataFileConnector.h"
#include "DataOPCConnector.h"

#include "easylogging++.h"

#include <string>
#include <fstream>

DataConnector::DataConnector() {
    useOPC = true;
}

DataConnector::~DataConnector() {
}

int DataConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "readValue: " << key;

    if(useOPC) {
        DataOPCConnector myDataOPCConnector;
        myDataOPCConnector.readValue (key, value);
        
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
        DataOPCConnector myDataOPCConnector;
        myDataOPCConnector.writeValue (key, value);

        return 0;
    }
    
    DataConnector::writeValue (key, value);

    return 0;
}