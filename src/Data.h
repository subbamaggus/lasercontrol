#ifndef EXAMPLEPROJECT_DATA_H
#define EXAMPLEPROJECT_DATA_H

#include <iostream>

//class connection;

class Data {
private:
    bool connected = false;
    //connection * conn;
public:
    static int method(std::string SerialNumber);
    static int number2formatted(int Integer, std::string & value);
    static int formatted2number(std::string value, int & Integer);
    int connect();
    bool isConnected();
};


#endif //EXAMPLEPROJECT_DATA_H