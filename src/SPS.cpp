#include "SPS.h"
#include "DataConnector.h"

#include "easylogging++.h"

// ######################################################
// read values

int SPS::registration() {
//    LOG(INFO) << "registration";

    std::string value = "";

    DataConnector::readValue("EINGANG_LASER1_ANMELDUNG", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::positionLaserReached() {
    std::string value = "";

    DataConnector::readValue("EINGANG_LASER1_POS1_ERREICHT", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::laserDone() {
    DataConnector::writeValue("AUSGANG_LASER1_POS1_FERTIG", "1");

    return 0;
}

int SPS::positionSannerReached() {
    std::string value = "";

    DataConnector::readValue("EINGANG_SCANNER1_POS1_ERREICHT", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::scanDone() {
    DataConnector::writeValue("AUSGANG_SCANNER1_POS1_FERTIG", "1");

    return 0;
}

int SPS::rescan() {
    DataConnector::writeValue("EINGANG_SCANNER1_WIEDERHOLEN", "1");

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

// ######################################################
// write values

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

int SPS::layoutAvailable() {
//    LOG(INFO) << "layoutAvailable";
    DataConnector::writeValue("AUSGANG_LASER1_LAYOUT_BEREIT", "1");

    // TODO reset after time?
    return 0;
}

int SPS::resetLayoutAvailable() {
//    LOG(INFO) << "resetLayoutAvailable";
    DataConnector::writeValue("AUSGANG_LASER1_LAYOUT_BEREIT", "0");

    return 0;
}

int SPS::setScanResult(int scanResult) {
//    LOG(INFO) << "setScanResult";
    DataConnector::writeValue("Scan1Pos1Ergebnis", "" + scanResult);

    return 0;
}

int SPS::setLayer(int layer) {
//    LOG(INFO) << "setLayer";
    DataConnector::writeValue("AUSGANG_LASER1_LAYER_BIT00", "0");
    DataConnector::writeValue("AUSGANG_LASER1_LAYER_BIT01", "0");
    DataConnector::writeValue("AUSGANG_LASER1_LAYER_BIT02", "0");
    DataConnector::writeValue("AUSGANG_LASER1_LAYER_BIT03", "0");
    DataConnector::writeValue("AUSGANG_LASER1_LAYER_BIT04", "0");

    return 0;
}


