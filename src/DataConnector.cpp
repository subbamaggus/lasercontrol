#include "DataConnector.h"

#include <iostream>
#include <fstream>

int DataConnector::readValue(std::string key, std::string & value) {
    std::ifstream infile(key);
    std::getline(infile, value);

    return 0;
}

int DataConnector::writeValue(std::string key, std::string value) {
    std::ofstream myfile;
    myfile.open (key);
    myfile << value;
    myfile.close();
    return 0;
}