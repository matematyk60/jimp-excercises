//
// Created by janek on 25.04.17.
//

#include "Pesel.h"


namespace academia {
    Pesel::Pesel(const char *input) {
        validatePESEL(input);
    }

    void Pesel::validatePESEL(const char *input) {
        if (PeselLength(input)) {
            throw InvalidPeselLength();
        } else if (PeselCharacter(input)) {
            throw InvalidPeselCharacter();
        } else if (PeselChecksum(input)) {
            throw InvalidPeselChecksum();
        }

    }

    bool Pesel::PeselChecksum(const char *input) {
        int suma = 0;
        suma = 9 * ((int) input[0] - 48) + 7 * ((int) input[1] - 48) + 3 * ((int) input[2] - 48) +
               1 * ((int) input[3] - 48) +
               9 * ((int) input[4] - 48) + 7 * ((int) input[5] - 48) + 3 * ((int) input[6] - 48) +
               1 * ((int) input[7] - 48) + 9 * ((int) input[8] - 48) + 7 * ((int) input[9] - 48);
        if (suma % 10 != ((int) input[10] - 48)) {
            return true;
        } else {
            return false;
        }
    }

    bool Pesel::PeselLength(const char *input) {
        int i = 0;
        while (input[i] != '\0') {
            i++;
        }
        if (i != 11) {
            return true;
        } else {
            return false;
        }
    }

    bool Pesel::PeselCharacter(const char *input) {
        int i = 0;
        while (input[i] != '\0') {
            if (input[i] < '0' || input[i] > '9') {
                return true;
            }
            i++;
        }
        return false;
    }

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &pesel, int checksum) : AcademiaDataValidationError(
            "Invalid PESEL(" + pesel + ") checksum: " + std::to_string(checksum)) {

    }

    InvalidPeselLength::InvalidPeselLength(std::string pesel, int length) :
            AcademiaDataValidationError("Invalid PESEL(" + pesel + ") length: " +
                                        std::to_string(length)) {
    }

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &pesel) :
            AcademiaDataValidationError("Invalid PESEL(" + pesel + ") character set") {
    }
}