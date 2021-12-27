#ifndef EXAMPLEPROJECT_DATA_H
#define EXAMPLEPROJECT_DATA_H

#include <iostream>

class Data {
public:
    static int method(std::string SerialNumber);
    static int number2formatted(int Integer, std::string & value);
    static int formatted2number(std::string value, int & Integer);
};


#endif //EXAMPLEPROJECT_DATA_H