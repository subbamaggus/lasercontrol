#include "SPS.h"
#include "DataConnector.h"

#include "easylogging++.h"

// ######################################################
// read values

int SPS::registration() {
    LOG(INFO) << "registration";

    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("EINGANG_LASER1_ANMELDUNG", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::positionLaserReached() {
    LOG(INFO) << "positionLaserReached";
    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("EINGANG_LASER1_POS1_ERREICHT", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::laserDone() {
    LOG(INFO) << "laserDone";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_POS1_FERTIG", "1");

    return 0;
}

int SPS::positionSannerReached() {
    LOG(INFO) << "positionSannerReached";
    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("EINGANG_SCANNER1_POS1_ERREICHT", value);

    if("1" == value)
        return 1;

    return 0;
}

int SPS::scanDone() {
    LOG(INFO) << "scanDone";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_SCANNER1_POS1_FERTIG", "1");

    return 0;
}

int SPS::rescan() {
    LOG(INFO) << "rescan";
    DataConnector myDataConnector;
    myDataConnector.writeValue("EINGANG_SCANNER1_WIEDERHOLEN", "1");

    return 0;
}

std::string SPS::getOrder() {
    LOG(INFO) << "getOrder";
    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("AuftragsNummer", value);

    return value;
}

std::string SPS::getSerialNumber() {
    LOG(INFO) << "getSerialNumber";
    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("SerienNummer", value);

    return value;
}

std::string SPS::getWT() {
    LOG(INFO) << "getWT";
    std::string value = "";

    DataConnector myDataConnector;
    myDataConnector.readValue("WerkStuecktraeger", value);

    return value;
}

// ######################################################
// write values

int SPS::passThrough() {
    LOG(INFO) << "passThrough";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_DURCHLAUF", "1");

    // TODO reset after time?
    return 0;
}

int SPS::resetPassThrough() {
    LOG(INFO) << "resetPassThrough";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_DURCHLAUF", "0");

    return 0;
}

int SPS::acknowledgeHandshake() {
    LOG(INFO) << "acknowledgeHandshake";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_KOMM_STATUS", "1");

    // TODO reset after time?
    return 0;
}

int SPS::resetAcknowledgeHandshake() {
    LOG(INFO) << "resetAcknowledgeHandshake";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_KOMM_STATUS", "0");

    return 0;
}

int SPS::layoutAvailable() {
    LOG(INFO) << "layoutAvailable";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_LAYOUT_BEREIT", "1");

    // TODO reset after time?
    return 0;
}

int SPS::resetLayoutAvailable() {
    LOG(INFO) << "resetLayoutAvailable";
    DataConnector myDataConnector;
    myDataConnector.writeValue("AUSGANG_LASER1_LAYOUT_BEREIT", "0");

    return 0;
}

int SPS::setScanResult(int scanResult) {
    LOG(INFO) << "setScanResult";
    DataConnector myDataConnector;
    myDataConnector.writeValue("Scan1Pos1Ergebnis", "" + scanResult);

    return 0;
}

int SPS::setLayer(int layer) {
    LOG(INFO) << "setLayer: " << layer;

    std::string value = "0";
    std::string i_str = "";

    for(int i = 0; i < 5; i++) {
        int channel = 1 << i;
        value = "0";
        if ((layer & (1 << i)) > 0)
            value = "1";

        i_str = std::to_string(i);

        DataConnector myDataConnector;
        myDataConnector.writeValue("AUSGANG_LASER1_LAYER_BIT0" + i_str, "" + value);
    }

    return 0;
}


