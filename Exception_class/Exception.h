//
// Created by я on 14.12.2022.
//

#ifndef SOUNDPROCESSOR_EXCEPTION_H
#define SOUNDPROCESSOR_EXCEPTION_H

enum {
    BAD_PROG_ARGS = 2,
    WRONG_FORMAT,
    WRONG_PROG_ARGS,
    WRONG_CONFIGURATION,
    WRONG_PARAMETRES
};

class Exceptions : std::exception {
    std::string reason;
    int return_code;
public:
    explicit Exceptions(std::string res, int code) : reason(std::move(res)), return_code(code) {}

    std::string what_err() {
        return this->reason;
    }

    int ret_code() {
        return this->return_code;
    }
};


#endif //SOUNDPROCESSOR_EXCEPTION_H
