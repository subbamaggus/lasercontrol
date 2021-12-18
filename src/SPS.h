#ifndef EXAMPLEPROJECT_SPS_H
#define EXAMPLEPROJECT_SPS_H

#include <iostream>

class SPS {
    
public:
    static int registration();

    static int positionReached();
    
    static std::string getOrder();
    static std::string getSerialNumber();
    static std::string getWT();
    
    static int passThrough();
    static int resetPassThrough();
    
    static int acknowledgeHandshake();
    static int resetAcknowledgeHandshake();
    
    static int layoutAvailable();
    static int resetLayoutAvailable();
    
    
private:
    std::string order = "orderno"; 
    std::string serial = "serial"; 
    std::string wt = "wtno"; 

};

    
#endif //EXAMPLEPROJECT_SPS_H