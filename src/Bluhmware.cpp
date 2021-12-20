#include "Bluhmware.h"
#include "SPS.h"
#include "Scanner.h"
#include "Laser.h"

#include "easylogging++.h"

#include <chrono>
#include <thread>

int Bluhmware::run() {
    LOG(INFO) << "run";
    std::string myOrder = "myOrder"; 
    std::string mySNR = "mySNR"; 
    std::string myWT = "myWT"; 
    
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        int avail = SPS::registration();
        if(1 == avail) {
            LOG(INFO) << "slope detected";
            
            SPS::acknowledgeHandshake();
            
            myOrder = SPS::getOrder();
            mySNR = SPS::getSerialNumber();
            myWT = SPS::getWT();
            
            LOG(INFO) << "readData Order:" << myOrder << ", SNR:" << mySNR << ", WT:" << myWT;
            
            //check data for SerienNummer
            
            if (false) { 
                LOG(INFO) << "pass through";
                
                SPS::passThrough();
                continue;
            }
            
            if (false) {
                LOG(INFO) << "layout not available";

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
            
            for (int layer = 1; layer <= 16; layer++) {
                LOG(INFO) << "marking layer " << layer;
                SPS::setLayer(layer);
                Laser::mark();
            }
            
            SPS::laserDone();
            
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
                
                scanResult = Scanner::scan();
                
                SPS::setScanResult(scanResult);

                SPS::scanDone();
                
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                
                if(!SPS::rescan()) {
                    LOG(INFO) << "do not rescan";
                    break;
                }
                
            }

        }
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