#ifndef EXAMPLEPROJECT_SPS_H
#define EXAMPLEPROJECT_SPS_H

#include <iostream>

class SPS {
    
public:
    static int registration();
    static std::string getOrder();
    static std::string getSerialNumber();
    static std::string getWT();
    static int passThrough();
    static int resetPassThrough();
private:
    std::string order = "orderno"; 
    std::string serial = "serial"; 
    std::string wt = "wtno"; 

};

    
#endif //EXAMPLEPROJECT_SPS_H