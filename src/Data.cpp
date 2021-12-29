#include "Data.h"

#include "easylogging++.h"

#include "example_unicode_utils.h"

#include <iostream>
#include <stdexcept>
#include <string>

bool Data::isConnected() {
    return connected;
}

int Data::connect() {
    LOG(INFO) << "connect: ";
    try
    {
        conn = new nanodbc::connection(NANODBC_TEXT("Driver={MySQL ODBC 5.1 Driver};Server=localhost;Database=test;User=root;"));
        LOG(INFO) << "connected";
        
        connected = true;
        
        return EXIT_SUCCESS;
    }
    catch (std::runtime_error const& e)
    {
        LOG(INFO) << "exception: " << e.what();
    }
    return EXIT_FAILURE;
}

int Data::method(std::string SerialNumber) {
    LOG(INFO) << "method: " << SerialNumber;
    
    try
    {
        //nanodbc::result row = execute(
        //    conn,
        //    NANODBC_TEXT("SELECT * FROM Zaehler where Linie='Linie1'"));
        //LOG(INFO) << "executed";
        //
        //for (int i = 1; row.next(); ++i)
        //{
        //    LOG(INFO) << i << ": " << convert(row.get<nanodbc::string>(1));
        //    int value = stoi(convert(row.get<nanodbc::string>(1)));
        //    LOG(INFO) << value;
        //}
        return EXIT_SUCCESS;
    }
    catch (std::runtime_error const& e)
    {
        LOG(INFO) << "exception: " << e.what();
    }
    return EXIT_FAILURE;
}

char* myitoa(int value, char* result, int base) {
    LOG(INFO) << "myitoa: " << value << ", " << base;
    
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}
    
int Data::number2formatted(int Integer, std::string & value) {
    LOG(INFO) << "number2formatted: " << Integer;
    
    char* char_arr;
    char_arr = &value[0];
    
    char_arr = myitoa(Integer, char_arr, 36);
    value = char_arr;
    
    return 0;
}

int Data::formatted2number(std::string value, int & Integer) {
    LOG(INFO) << "formatted2number: " << value;

    char* char_arr;
    char_arr = &value[0];
    
    Integer = std::strtol(char_arr, NULL, 36);
    
    return 0;
}