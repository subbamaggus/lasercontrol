#ifndef EXAMPLEPROJECT_DATA_H
#define EXAMPLEPROJECT_DATA_H

#include <iostream>

#include <nanodbc/nanodbc.h>

class Data {
private:
    bool connected = false;
    nanodbc::connection * conn;
public:
    int method(std::string SerialNumber);
    int number2formatted(int Integer, std::string & value);
    int formatted2number(std::string value, int & Integer);
    int connect();
    bool isConnected();
    
    Data();
    ~Data();
};


#endif //EXAMPLEPROJECT_DATA_H