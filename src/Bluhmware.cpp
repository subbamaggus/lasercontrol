#include "Bluhmware.h"
#include "SPS.h"
#include "Scanner.h"
#include "Laser.h"
#include "Data.h"

#include "easylogging++.h"

#include <chrono>
#include <thread>

int Bluhmware::registerWT() {
    int ret = -1;
    LOG(INFO) << "registerWT()";

    SPS::acknowledgeHandshake();

    myOrder = SPS::getOrder();
    mySNR = SPS::getSerialNumber();
    myWT = SPS::getWT();

    LOG(INFO) << "readData Order:" << myOrder << ", SNR:" << mySNR << ", WT:" << myWT;
    
    Data::method(mySNR);

    bool layout_VN1_avail = true;
    bool layout_VN2_avail = true;
    
    if (layout_VN1_avail) {
        LOG(INFO) << "layout vn1 available";

        SPS::layoutAvailable();
        ret = 0;
    }

    SPS::resetAcknowledgeHandshake();
    SPS::resetLayoutAvailable();
    
    return ret;
}

int Bluhmware::markPositionReached(int pos) {
    
    for (int layer = 1; layer <= 16; layer++) {
        LOG(INFO) << "marking layer " << layer;
        
        SPS::setLayer(layer);
        
        Laser::mark();
    }
    
    SPS::laserDone();
    
    return 0;    
}

int Bluhmware::scanPositionReached(int pos) {
    int scanResult = Scanner::scan();

    SPS::setScanResult(scanResult);

    SPS::scanDone();

    return scanResult;
}

int Bluhmware::run() {
    LOG(INFO) << "run";
    int last_avail = 0;
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        int avail = SPS::registration();
        LOG(INFO) << "return value " << avail;
        if(1 == avail && 0 == last_avail) {
            LOG(INFO) << "slope detected";
            
            this->registerWT();

            if (false) {
                LOG(INFO) << "pass through";

                SPS::passThrough();
                continue;
            }


            int posistionReached = 0;
            int retry = 10;
            while (0 == posistionReached) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                posistionReached = SPS::positionLaserReached();
                retry --;

                if(retry <= 0) {
                    LOG(INFO) << "retries exceeded";
                    break;
                }
            }

            this->markPositionReached(1);

            int scanResult = -1;

            while (scanResult < 0) {
                posistionReached = 0;
                retry = 10;
                while (0 == posistionReached) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));

                    posistionReached = SPS::positionSannerReached();
                    retry --;

                    if(retry <= 0) {
                        LOG(INFO) << "retries exceeded";
                        break;
                    }
                }
                
                this->scanPositionReached(1);

                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                if(!SPS::rescan()) {
                    LOG(INFO) << "do not rescan";
                    break;
                }

            }

        }
        
        last_avail = avail;
    }

    return 0;
}

int Bluhmware::setLaser(int parameter_laser) {
    LOG(INFO) << "setLaser: " << parameter_laser;

    laser = parameter_laser;

    return 0;
}

int Bluhmware::getLaser() {
    LOG(INFO) << "getLaser" << laser;

    return laser;
}

Bluhmware::Bluhmware() {
    LOG(INFO) << "Bluhmware";
}