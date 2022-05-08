#ifndef EXAMPLEPROJECT_DATACONNECTOR_H
#define EXAMPLEPROJECT_DATACONNECTOR_H

#include <iostream>

class DataConnector {
public:
    int readValue(std::string key, std::string & value);
    int writeValue(std::string key, std::string value);
    bool useOPC;
};


#endif //EXAMPLEPROJECT_DATACONNECTOR_H