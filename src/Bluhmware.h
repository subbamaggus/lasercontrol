#ifndef EXAMPLEPROJECT_BLUHMWARE_H
#define EXAMPLEPROJECT_BLUHMWARE_H

#include <iostream>

class Bluhmware {
public:
    int run();
    int setLaser(int parameter_laser);
    int getLaser();
    
    int registerWT();
    int markPositionReached(int pos);
    int scanPositionReached(int pos);
    Bluhmware();
private:
    int laser = -1;
    
    std::string myOrder = "myOrder";
    std::string mySNR = "mySNR";
    std::string myWT = "myWT";
};


#endif //EXAMPLEPROJECT_BLUHMWARE_H