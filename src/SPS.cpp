#include "SPS.h"
#include "DataConnector.h"

    
int SPS::registration() {
    std::string value = ""; 
    
    DataConnector::readValue("EINGANG_LASER1_ANMELDUNG", value);
    
    if("1" == value)
        return 1;
    
    return 0;
}


std::string SPS::getOrder() {
    std::string value = ""; 
    
    DataConnector::readValue("AuftragsNummer", value);
    
    return value;
}

std::string SPS::getSerialNumber() {
    std::string value = ""; 
    
    DataConnector::readValue("SerienNummer", value);
    
    return value;
}

std::string SPS::getWT() {
    std::string value = ""; 
    
    DataConnector::readValue("WerkStuecktraeger", value);
    
    return value;
}

int SPS::passThrough() {
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "1");
    
    return 0;
}

int SPS::resetPassThrough() {
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "0");
    
    return 0;
}
