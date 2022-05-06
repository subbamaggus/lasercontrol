#ifndef EXAMPLEPROJECT_DATAOPCCONNECTOR_H
#define EXAMPLEPROJECT_DATAOPCCONNECTOR_H

#include <iostream>

class DataOPCConnector {
public:
    static int readValue(std::string key, std::string & value);
    static int writeValue(std::string key, std::string value);
};


#endif //EXAMPLEPROJECT_DATAOPCCONNECTOR_H