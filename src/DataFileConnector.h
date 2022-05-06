#ifndef EXAMPLEPROJECT_DATAFILECONNECTOR_H
#define EXAMPLEPROJECT_DATAFILECONNECTOR_H

#include <iostream>

class DataFileConnector {
public:
    static int readValue(std::string key, std::string & value);
    static int writeValue(std::string key, std::string value);
};


#endif //EXAMPLEPROJECT_DATAFILECONNECTOR_H