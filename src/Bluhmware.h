#ifndef EXAMPLEPROJECT_BLUHMWARE_H
#define EXAMPLEPROJECT_BLUHMWARE_H

class Bluhmware {
public:
    int run();
    int setLaser(int parameter_laser);
    int getLaser();
    Bluhmware();
private:
    int laser = -1;
};

    
#endif //EXAMPLEPROJECT_BLUHMWARE_H