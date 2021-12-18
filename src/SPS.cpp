#include "SPS.h"
#include "DataConnector.h"

    
int SPS::registration() {
    LOG(DEBUG) << "registration";
    
    std::string value = ""; 
    
    DataConnector::readValue("EINGANG_LASER1_ANMELDUNG", value);
    
    if("1" == value)
        return 1;
    
    return 0;
}


std::string SPS::getOrder() {
    LOG(DEBUG) << "getOrder";
    std::string value = ""; 
    
    DataConnector::readValue("AuftragsNummer", value);
    
    return value;
}

std::string SPS::getSerialNumber() {
    LOG(DEBUG) << "getSerialNumber";
    std::string value = ""; 
    
    DataConnector::readValue("SerienNummer", value);
    
    return value;
}

std::string SPS::getWT() {
    LOG(DEBUG) << "getWT";
    std::string value = ""; 
    
    DataConnector::readValue("WerkStuecktraeger", value);
    
    return value;
}

int SPS::passThrough() {
    LOG(DEBUG) << "passThrough";
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "1");
    
    // TODO reset after time?
    return 0;
}

int SPS::resetPassThrough() {
    LOG(DEBUG) << "resetPassThrough";
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "0");
    
    return 0;
}

int SPS::acknowledgeHandshake() {
    LOG(DEBUG) << "acknowledgeHandshake";
    DataConnector::writeValue("AUSGANG_LASER1_KOMM_STATUS", "1");
    
    // TODO reset after time?
    return 0;
}

int SPS::resetAcknowledgeHandshake() {
    LOG(DEBUG) << "resetAcknowledgeHandshake";
    DataConnector::writeValue("AUSGANG_LASER1_KOMM_STATUS", "0");
    
    return 0;
}
