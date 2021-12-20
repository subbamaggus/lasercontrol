#include "Data.h"

#include "easylogging++.h"

int Data::method(std::string SerialNumber) {
    LOG(INFO) << "method: " << SerialNumber;
    return 0;
}