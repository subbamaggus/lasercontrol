install visual studio 2019
install cygwin with gcc-core
https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html

https://mirkokiefer.com/cmake-by-example-f95eb47d45b1
http://www.coder-welten.de/einstieg/hallo-welt.htm

using these libs:
https://github.com/brofield/simpleini
https://github.com/amrayn/easyloggingpp



seriennummer generierung: [OPCUALinie1]

read config
    Settings.SpecialFields.NVE.StandortL1.ArbeitsplatzL1
    SNR Format: <Standort><Arbeitsplatz><YY><DDD><[0-9A-Z][0-9A-Z][0-9A-Z][0-9A-Z]>


while true
    pause (later callback)
    
    if(readPLC EINGANG_ANMELDUNG_SNR)
        readPLC AuftragsNummer
        readPLC WerkStuecktraeger
        
        readMEM last_id
        increment id
        calculate fullid
        
        writePLC SerienNummer
        
        writeMEM fullid as last_id
        
        writePLC AUSGANG_KOMM_SNR_STATUS


Laser Station: [OPCSerNr1]

while true
    pause (later callback)
    
    writePLC AUSGANG_LASER1_IPC_BEREIT

    if (readPLC EINGANG_LASER1_ANMELDUNG)
        readPLC AuftragsNummer
        readPLC WerkStuecktraeger
        readPLC SerienNummer
        
        check data for SerienNummer

        if (durchlauf)
            writePLC AUSGANG_LASER1_DURCHLAUF
            continue
        
        writePLC AUSGANG_LASER1_KOMM_STATUS ???
        
        if (!layoutfile exists)
            continue
        
        writePLC AUSGANG_LASER1_LAYOUT_BEREIT
        
        set slots
        
        if (readPLC EINGANG_LASER1_POS1_ERREICHT)
            load layout
            while(layer)
                print layer X
                    writePLC AUSGANG_LASER1_LAYER_BIT00
                    writePLC AUSGANG_LASER1_LAYER_BIT01
                    writePLC AUSGANG_LASER1_LAYER_BIT02
                    writePLC AUSGANG_LASER1_LAYER_BIT03
                    writePLC AUSGANG_LASER1_LAYER_BIT04
            writePLC AUSGANG_LASER1_POS1_FERTIG
            
        if (readPLC EINGANG_SCANNER1_POS1_ERREICHT)
            while(readPLC EINGANG_SCANNER1_WIEDERHOLEN)
                scan pos1

                writePLC Scan1Pos1Ergebnis
                writePLC AUSGANG_SCANNER1_POS1_FERTIG

                if (readPLC EINGANG_SCANNER1_ABBRUCH)
                    break

        
