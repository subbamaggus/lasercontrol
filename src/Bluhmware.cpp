#include "Bluhmware.h"
#include "easylogging++.h"
#include "DataConnector.h"

#include <chrono>
#include <thread>

int Bluhmware::run() {
    LOG(INFO) << "run";
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
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