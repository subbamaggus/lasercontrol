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
        //std::list<datasource> list_datasources;
        //list_datasources = nanodbc::list_datasources();
        //std::list<datasource>::iterator it;
        //
        //for (it = list_datasources.begin(); it != list_datasources.end(); ++it){
        //    std::cout << it->stringname;
        //}
        
        connection conn(NANODBC_TEXT("localhost32-test"));
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