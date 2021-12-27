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
            NANODBC_TEXT("SELECT * FROM Zaehler"));
        LOG(INFO) << "executed";
        
        for (int i = 1; row.next(); ++i)
        {
            LOG(INFO) << i << " :" << convert(row.get<nanodbc::string>(0)) << " "
                 << convert(row.get<nanodbc::string>(1)) << " "
                 << convert(row.get<nanodbc::string>(2)) << " ";
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