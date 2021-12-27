#include "Data.h"

#include "easylogging++.h"

#include "example_unicode_utils.h"
#include <nanodbc/nanodbc.h>

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace nanodbc;

int Data::method(std::string SerialNumber) {
    LOG(INFO) << "method: " << SerialNumber;
    
    try
    {
        connection conn(NANODBC_TEXT("Driver={MySQL ODBC 5.1 Driver};Server=localhost;Database=test;User=root;"));
        LOG(INFO) << "connected";
        
        result row = execute(
            conn,
            NANODBC_TEXT("SELECT * FROM Zaehler where Linie='Linie1'"));
        LOG(INFO) << "executed";
        
        for (int i = 1; row.next(); ++i)
        {
            LOG(INFO) << i << ": " << convert(row.get<nanodbc::string>(1));
            int value = stoi(convert(row.get<nanodbc::string>(1)));
            LOG(INFO) << value;
        }
        return EXIT_SUCCESS;
    }
    catch (runtime_error const& e)
    {
        LOG(INFO) << "exception: " << e.what();
    }
    //return EXIT_FAILURE;
    return 0;
}

int Data::number2formatted(int Integer, std::string & value) {
    LOG(INFO) << "number2formatted: " << Integer;
    
    return 0;
}

int Data::formatted2number(std::string value, int & Integer) {
    LOG(INFO) << "formatted2number: " << value;

    char* char_arr;
    char_arr = &value[0];
    
    Integer = std::strtol(char_arr, NULL, 36);
    
    return 0;
}