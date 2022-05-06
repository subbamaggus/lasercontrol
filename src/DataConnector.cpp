#include "DataConnector.h"
#include "DataFileConnector.h"

#include "easylogging++.h"

#include <string> // for string class
#include <fstream>

//std::string folder = "data/";

int DataConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "readValue: " << key;

    DataFileConnector::readValue (key, value);

    LOG(INFO) << "returning: " << value;

    return 0;
}

int DataConnector::writeValue(std::string key, std::string value) {
    LOG(INFO) << "writeValue: " << key << ", " << value;

    DataConnector::writeValue (key, value);

    return 0;
}