#ifndef EXAMPLEPROJECT_BLUHMWARE_H
#define EXAMPLEPROJECT_BLUHMWARE_H

class Bluhmware {
public:
    int run();
    int setLaserPosition(int parameter_laser, int parameter_position);
    Bluhmware();
private:
    int laser = -1;
    int position = -1;
};

    
#endif //EXAMPLEPROJECT_BLUHMWARE_H