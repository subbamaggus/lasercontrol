#include "SPS.h"
#include "DataConnector.h"

    
int SPS::registration() {
    std::string value = ""; 
    
    DataConnector::readValue("EINGANG_LASER1_ANMELDUNG", value);
    
    if("1" == value)
        return 1;
    
    return 0;
}