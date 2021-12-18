#include "DataConnector.h"

#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>

std::string readFileIntoString(const std::string& path) {
    // TODO error handling
    struct stat sb{};
    std::string res;

    FILE* input_file = fopen(path.c_str(), "r");
    if (input_file == nullptr) {
        perror("fopen");
    }

    stat(path.c_str(), &sb);
    res.resize(sb.st_size);
    fread(const_cast<char*>(res.data()), sb.st_size, 1, input_file);
    fclose(input_file);

    return res;
}

int DataConnector::readValue(std::string key, std::string & value) {
    value = readFileIntoString(key);
    return 0;
}