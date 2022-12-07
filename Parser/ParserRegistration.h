//
// Created by я on 04.12.2022.
//

#ifndef SOUNDPROCESSOR_PARSERREGISTRATION_H
#define SOUNDPROCESSOR_PARSERREGISTRATION_H

#include "Parser.h"

namespace ParserRegistration {
    class ParserRegistration {
    public:
        ParserRegistration() = default;
        ParserRegistration(const std::string description) {
            Parser::Instance().ParserReg(description);
        }
    };

}

#endif //SOUNDPROCESSOR_PARSERREGISTRATION_H
