#include "DataOPCConnector.h"

#include "easylogging++.h"

#include <string> // for string class
#include <fstream>

//std::string folder = "data/";

int DataOPCConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "readValue: " << key;

//    std::ifstream infile(folder + key);
//    std::getline(infile, value);
//
//    LOG(INFO) << "returning: " << value;

    return 0;
}

int DataOPCConnector::writeValue(std::string key, std::string value) {
    LOG(INFO) << "writeValue: " << key << ", " << value;

//    std::ofstream myfile;
//    myfile.open(folder + key);
//    myfile << value;
//    myfile.close();

    return 0;
}