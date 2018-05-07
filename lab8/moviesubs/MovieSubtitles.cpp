//
// Created by hubert on 07.05.18.
//

#include "MovieSubtitles.h"

using namespace moviesubs;

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds,
                                            int frame_per_second,
                                            std::istream *in,
                                            std::ostream *out) {
    if(frame_per_second < 0)
        throw std::invalid_argument("błąd");

    int offset = offset_in_micro_seconds * frame_per_second / 1000;
    std::regex wzor{R"(\{([\d]+)\}\{([\d]+)\}([^\n]+))"};
    std::string tekst;
    std::cmatch cmatch;
    int linia = 1;
    while(std::getline(*in, tekst)) {
        if(std::regex_match(tekst.c_str(), cmatch, wzor)) {

            if(std::stoi(cmatch[1]) + offset < 0)
                throw NegativeFrameAfterShift(linia, tekst);

            if(std::stoi(cmatch[1]) > std::stoi(cmatch[2]))
                throw SubtitleEndBeforeStart(linia, tekst);

            *out << "{" << std::stoi(cmatch[1]) + offset << "}"
                 << "{" << std::stoi(cmatch[2]) + offset << "}"
                 << cmatch[3] << "\n";
        }else{
            throw InvalidSubtitleLineFormat(linia, tekst);
        }
        linia++;
    }
}


std::string SubRipSubtitles::zmiana_czasu(int klatki, const std::cmatch &cmatch) {
    std::vector<int> czas_int;
    std::vector<std::string> czas_str;
    std::string napis, wynik;
    czas_int.push_back(0);

    for(int i = 1; i < cmatch.size(); i++)
        czas_int.push_back(std::stoi(cmatch[i]));

    int tmp = (czas_int[4] + klatki) / 1000;
    czas_int[4] = (czas_int[4] + klatki) % 1000;
    for(int i = 3; i > 0 && tmp > 0; --i) {
        czas_int[i] += tmp;
        tmp = czas_int[i] / 60;
    }

    tmp = (czas_int[8] + klatki) / 1000;
    czas_int[8] = (czas_int[8] + klatki) % 1000;
    for(int i = 7; i >= 5 && tmp > 0; --i) {
        czas_int[i] += tmp;
        tmp = czas_int[i] / 60;
    }

    return getString(czas_int, czas_str, napis, wynik);
}

std::string & SubRipSubtitles::getString(const std::vector<int> &czas_int,
                           std::vector<std::string> &czas_str,
                           std::string &napis,
                           std::string &wynik) const {
    for(int i = 1; i < czas_int.size(); i++) {
        napis = std::__cxx11::to_string(czas_int[i]);
        if (i == 4 || i == 8) {
            if (napis.length() > 2) {
                czas_str.push_back(napis);
            } else if (napis.length() > 1) {
                czas_str.push_back("0" + napis);
            } else {
                czas_str.push_back("00" + napis);
            }
        } else {
            if (napis.length() > 1) {
                czas_str.push_back(napis);
            } else {
                czas_str.push_back("0" + napis);
            }
        }
    }
    wynik = czas_str[0] + ":" + czas_str[1] + ":" + czas_str[2] + "," + czas_str[3] + " --> ";
    wynik += czas_str[4] + ":" + czas_str[5] + ":" + czas_str[6] + "," + czas_str[7] + "\n";
    return wynik;
}


void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds,
                                          int frame_per_second,
                                          std::istream *in,
                                          std::ostream *out) {

    std::regex wzor {R"(([\d]+)\:([\d]+):([\d]+),([\d]+)\ \-\-\>\ ([\d]+)\:([\d]+):([\d]+),([\d]+))"};

    std::cmatch cmatch;
    std::string tekst;
    bool czas_err = false;
    bool pusta = true;
    int pierwszy, sekundy, err = 1;
    int drugi,  linia = 1;

    if(frame_per_second <= 0)
        throw std::invalid_argument("fps <= 0");

    sekundy = offset_in_micro_seconds;

    while(std::getline(*in, tekst)) {
        if (std::regex_match(tekst.c_str(), cmatch, wzor)) {

            pierwszy = std::stoi(cmatch[1])*3600000 + std::stoi(cmatch[2]) * 60000;
            pierwszy += std::stoi(cmatch[3]) * 1000 + std::stoi(cmatch[4]);

            drugi = std::stoi(cmatch[5])*3600000 + std::stoi(cmatch[6]) * 60000;
            drugi += std::stoi(cmatch[7]) * 1000 + std::stoi(cmatch[8]);

            if(pierwszy < -sekundy) {
                throw NegativeFrameAfterShift(linia, tekst);
            }else if (pierwszy > drugi) {
                throw SubtitleEndBeforeStart(linia, tekst);
            }

            *out << zmiana_czasu(sekundy, cmatch);
            linia++;
            czas_err = false;
        } else if(czas_err) {
            throw InvalidSubtitleLineFormat(linia, tekst);
        } else {
            if (pusta) {
                czas_err = true;
                if(std::stoi(tekst) != err) {
                    throw OutOfOrderFrames(linia, tekst);
                }
                err++;
            }
            pusta = tekst.empty();
            *out << tekst << "\n";
        }
    }
}


