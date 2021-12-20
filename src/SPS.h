#ifndef EXAMPLEPROJECT_SPS_H
#define EXAMPLEPROJECT_SPS_H

#include <iostream>

class SPS {

public:
    static int registration();

    static int positionLaserReached();
    static int laserDone();
    static int positionSannerReached();
    static int scanDone();
    static int rescan();

    static int setLayer(int layer);

    static std::string getOrder();
    static std::string getSerialNumber();
    static std::string getWT();

    static int passThrough();
    static int resetPassThrough();

    static int acknowledgeHandshake();
    static int resetAcknowledgeHandshake();

    static int layoutAvailable();
    static int resetLayoutAvailable();

    static int setScanResult(int scanResult);
private:
    std::string order = "orderno";
    std::string serial = "serial";
    std::string wt = "wtno";

};


#endif //EXAMPLEPROJECT_SPS_H