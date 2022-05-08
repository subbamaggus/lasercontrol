#include "DataOPCConnector.h"
#include "easylogging++.h"
#include <string>

DataOPCConnector::DataOPCConnector() {
    LOG(INFO) << "DataOPCConnector::DataOPCConnector()";
    UA_StatusCode retval;
    
    client = UA_Client_new();
    UA_ClientConfig_setDefault(UA_Client_getConfig(client));
    
    retval = UA_Client_connect(client, "opc.tcp://JM-W10-KE-MKENB:4980/csv");
    if(retval != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
    }
    
    LOG(INFO) << "initialized";
}

DataOPCConnector::~DataOPCConnector() {
    UA_Client_disconnect(client);
    UA_Client_delete(client);
}

int DataOPCConnector::readValue(std::string key, std::string & value) {
    LOG(INFO) << "DataOPCConnector::readValue: " << key;
    
    UA_StatusCode retval;
    
    UA_NodeId nodeId = UA_NODEID(&key[0]);
    
    UA_String opc_value;
    UA_Variant *val = UA_Variant_new();
    retval = UA_Client_readValueAttribute(client, nodeId, val);
    if(retval == UA_STATUSCODE_GOOD && UA_Variant_isScalar(val) &&
       val->type == &UA_TYPES[UA_TYPES_STRING]) {
            opc_value = *(UA_String*)val->data;
            printf("the value is: %.*s\n", (int)opc_value.length, opc_value.data);
            
            char* convert = (char*)UA_malloc(sizeof(char)*opc_value.length+1);
            memcpy(convert, opc_value.data, opc_value.length );
            convert[opc_value.length] = '\0';
            
            std::string str(convert);
            value = str;
    }
    
    UA_Variant_delete(val);

    return 0;
}

int DataOPCConnector::writeValue(std::string key, std::string value) {

    return 0;
}