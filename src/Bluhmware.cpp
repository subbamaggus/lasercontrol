#include "Bluhmware.h"
#include "easylogging++.h"
#include "SPS.h"

#include <chrono>
#include <thread>

int Bluhmware::run() {
    LOG(INFO) << "run";
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        int avail = SPS::registration();
        if(1 == avail) {
            LOG(INFO) << "slope detected";
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