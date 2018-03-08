//
// Created by hubert on 08.03.18.
//

#include <iostream>
#include "Polybius.h"
#include <fstream>
#include <cstring>


int main(int argc, char* argv[]){

    std::fstream plik_wej;
    plik_wej.open(argv[1], std::ios::in	);

    std::fstream plik_wyj;
    plik_wyj.open(argv[2], std::ios::out);

    if(plik_wej.good() == true){
        std::cout << "Uzyskano dostep do pliku wejsciowego!" << std::endl;
    }

    if(std::strcmp(argv[3], "1")){
        std::string dane;
        plik_wej >> dane;
        std::string szyfr = PolybiusCrypt(dane);
        plik_wyj << szyfr;
        std::cout << "Zapisano szyfr do pliku";
        return 0;
    }

    if(std::strcmp(argv[3], "0")){
        std::string dane;
        plik_wej >> dane;
        std::string wiadomosc = PolybiusDecrypt(dane);

        plik_wyj << wiadomosc;
        std::cout << "Zapisano wiadomosc do pliku";
        return 0;
    }

    std::cout << "Błąd zapisu pliku.";
}