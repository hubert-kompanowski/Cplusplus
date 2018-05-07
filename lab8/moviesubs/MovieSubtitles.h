//
// Created by hubert on 07.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <ostream>
#include <iostream>
#include <regex>
#include <exception>
#include <iosfwd>
#include <stdexcept>
#include <string>


namespace moviesubs{
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds,
                                         int frame_per_second, std::istream *in,
                                         std::ostream *out) = 0;
        ~MovieSubtitles(){
            std::cout << "destruktor MovieSubtitles" << std::endl;
        }
    };
    
    class MicroDvdSubtitles : public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int, int, std::istream*, std::ostream*) override;

    };

    class SubRipSubtitles : public  MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(int, int, std::istream*, std::ostream*) override;
        std::string zmiana_czasu(int klatki, const std::cmatch &cmatch);

        std::string &getString(const std::vector<int> &, std::vector<std::string> &, std::string &, std::string &) const;
    };

    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException(int l, const std::string &t) : std::invalid_argument("At line "  + std::to_string(l) + ": " + t), linia(l){}
        int LineAt() const{
            return linia;
        }
    private:
        int linia;
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift(int l, const std::string &t) : SubtitlesException(l, t) {}
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        SubtitleEndBeforeStart(int l, const std::string &t) : SubtitlesException(l, t) {}
    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat(int l, const std::string &t) : SubtitlesException(l, t) {}
    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        OutOfOrderFrames(int l, const std::string &t) : SubtitlesException(l, t) {}
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        MissingTimeSpecification(int l, const std::string &t) : SubtitlesException(l, t) {}
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
