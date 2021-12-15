#include <iostream>
#include "Formula.h"
#include "SimpleIni.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
    std::cout << "Bla: " << Formula::bla(2) << std::endl;
    
    CSimpleIniA ini;
	ini.SetUnicode();
    
    SI_Error rc = ini.LoadFile("example.ini");
	if (rc < 0) { /* handle error */ };

	const char* pv;
	pv = ini.GetValue("section", "key1", "default");
    std::cout << "ini1: " << pv << std::endl;

	pv = ini.GetValue("section", "key2", "default");
    std::cout << "ini2: " << pv << std::endl;

    LOG(INFO) << "My first info log using default logger";
    
    return 0;
}