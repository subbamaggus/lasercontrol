#ifndef EXAMPLEPROJECT_DATAOPCCONNECTOR_H
#define EXAMPLEPROJECT_DATAOPCCONNECTOR_H

#include <iostream>
#include "open62541/open62541.h"

class DataOPCConnector {
public:
    DataOPCConnector();
    ~DataOPCConnector();
    
    int readValue(std::string key, std::string & value);
    int writeValue(std::string key, std::string value);
private:
    UA_Client *client;
};


#endif //EXAMPLEPROJECT_DATAOPCCONNECTOR_H