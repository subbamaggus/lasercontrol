#ifndef EXAMPLEPROJECT_DATACONNECTOR_H
#define EXAMPLEPROJECT_DATACONNECTOR_H

#include <iostream> 
#include <string> // for string class 
#include <fstream>

class DataConnector {
public:
    static int readValue(std::string key, std::string & value);
    static int writeValue(std::string key, std::string value);
};

    
#endif //EXAMPLEPROJECT_DATACONNECTOR_H