//
// Created by matematyk60 on 25.04.17.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>

namespace academia {
    class Pesel {
    public:
        Pesel(const char *input);
        static void validatePESEL(const char *input);
        static bool PeselChecksum(const char *input);
        static bool PeselLength(const char *input);
        static bool PeselCharacter(const char *input);
    };

    class AcademiaDataValidationError : public std::runtime_error{
    public:
        AcademiaDataValidationError(std::string message) : std::runtime_error(message){
            message_ = message;
        }
        virtual ~AcademiaDataValidationError(){};
    private:
        std::string message_;
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError{
    public:
        InvalidPeselChecksum(const std::string &pesel = "PESEL", int checksum = 0);
    };

    class InvalidPeselLength : public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string  = "PESEL", int length = 0);
    private:
        std::string message_;
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError{
    public:
        InvalidPeselCharacter(const std::string &pesel = "PESEL");
    private:
        std::string message_;
    };



}

#endif //JIMP_EXERCISES_PESEL_H
