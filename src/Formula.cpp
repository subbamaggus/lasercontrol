#include "Formula.h"

#include "easylogging++.h"

int Formula::bla(int arg1) {
    LOG(INFO) << "test logging";
    return arg1 * 3;
}

int Formula::maggus(int arg1, int arg2) {
    return arg1 + arg2;
}