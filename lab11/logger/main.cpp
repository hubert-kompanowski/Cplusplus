//
// Created by hubert on 23.05.18.
//

#include <Logger.h>
#include <iostream>
#include <sstream>

using logger::Logger;

int main() {
    std::stringstream out;
    Logger<std::stringstream> logger(&out);



    logger.info("Hello World!");
    logger.debug("Hello World!");
    logger.warning("Hello World!");
    logger.error("Hello World!");




    return 0;
}