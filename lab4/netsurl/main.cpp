//
// Created by hubert on 18.03.18.
//


#include "SimpleUrl.h"

using namespace nets;

int main(){

    std::string url = "http://geofl.ge/#!/page_saxelmdzvanelo";
    std::string url2 = "mailto:someone@example.com?subject=This%20is%2:999ggg0the%20subject&cc=someone_else@example.com&body=This%#20is%20the%20body";


    SimpleUrl adres1(url);

    std::cout <<adres1.Fragment() << " ";

    SimpleUrl adres2(url2);

    std::cout <<adres2.Fragment();

}



//|((\S*)((\@))([^/]*)((\?(\S*))|$))