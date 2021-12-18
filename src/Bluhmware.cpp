#include "Bluhmware.h"
#include "easylogging++.h"

int Bluhmware::run() {
    LOG(INFO) << "run";
    return 0;
}

int Bluhmware::setLaser(int parameter_laser) {
    LOG(INFO) << "laser: " << parameter_laser;
    
    laser = parameter_laser;
    
    return 0;
}

Bluhmware::Bluhmware() {
    LOG(INFO) << "init Bluhmware";
}