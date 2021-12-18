#include "SPS.h"
#include "DataConnector.h"

    
int SPS::registration() {
    LOG(INFO) << "registration";
    
    std::string value = ""; 
    
    DataConnector::readValue("EINGANG_LASER1_ANMELDUNG", value);
    
    if("1" == value)
        return 1;
    
    return 0;
}


std::string SPS::getOrder() {
//    LOG(INFO) << "getOrder";
    std::string value = ""; 
    
    DataConnector::readValue("AuftragsNummer", value);
    
    return value;
}

std::string SPS::getSerialNumber() {
//    LOG(INFO) << "getSerialNumber";
    std::string value = ""; 
    
    DataConnector::readValue("SerienNummer", value);
    
    return value;
}

std::string SPS::getWT() {
//    LOG(INFO) << "getWT";
    std::string value = ""; 
    
    DataConnector::readValue("WerkStuecktraeger", value);
    
    return value;
}

int SPS::passThrough() {
//    LOG(INFO) << "passThrough";
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "1");
    
    // TODO reset after time?
    return 0;
}

int SPS::resetPassThrough() {
//    LOG(INFO) << "resetPassThrough";
    DataConnector::writeValue("AUSGANG_LASER1_DURCHLAUF", "0");
    
    return 0;
}

int SPS::acknowledgeHandshake() {
//    LOG(INFO) << "acknowledgeHandshake";
    DataConnector::writeValue("AUSGANG_LASER1_KOMM_STATUS", "1");
    
    // TODO reset after time?
    return 0;
}

int SPS::resetAcknowledgeHandshake() {
//    LOG(INFO) << "resetAcknowledgeHandshake";
    DataConnector::writeValue("AUSGANG_LASER1_KOMM_STATUS", "0");
    
    return 0;
}
