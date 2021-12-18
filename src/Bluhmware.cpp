#include "Bluhmware.h"
#include "easylogging++.h"
#include "DataConnector.h"

#include <chrono>
#include <thread>

int Bluhmware::run() {
    LOG(INFO) << "run";
    std::string key = "datafile.txt"; 
    std::string value = "pass by value"; 
    
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        DataConnector::readValue (key, value);
        if(value == "1") {
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