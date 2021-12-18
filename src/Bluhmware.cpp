#include "Bluhmware.h"
#include "SPS.h"

#include "easylogging++.h"

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
                // passthrough
                LOG(INFO) << "pass through";
                
                SPS::passThrough();
                continue;
            }
            
            if (false) {
                // layout not available
                continue;
            }
            
            int posistionReached = 0;
            int timeout = 5; // TODO timeout and sleep time, keep them together
            while (0 == posistionReached && timeout > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));                

                posistionReached = SPS::positionReached();
                timeout --;
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