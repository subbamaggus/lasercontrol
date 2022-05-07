#include "DataFileConnector.h"

#include "easylogging++.h"

#include <string> // for string class
#include <fstream>

std::string folder = "data/";

int DataFileConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "DataFileConnector readValue: " << key;

    std::ifstream infile(folder + key);
    std::getline(infile, value);

    LOG(INFO) << "DataFileConnector returning: " << value;

    return 0;
}

int DataFileConnector::writeValue(std::string key, std::string value) {
    LOG(INFO) << "DataFileConnector writeValue: " << key << ", " << value;

    std::ofstream myfile;
    myfile.open(folder + key);
    myfile << value;
    myfile.close();

    return 0;
}