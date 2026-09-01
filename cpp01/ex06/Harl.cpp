#include "Harl.hpp"
#include <iostream>

Harl::Harl() {

}

Harl::~Harl() {

}

void    Harl::complain(std::string level) {
    typedef void (Harl::*HarlFunctions)(void);
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    HarlFunctions functions[4] = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return ;
        }
    }
}

Level   getLevel(const std::string& levelStr) {
    if (levelStr == "DEBUG") return DEBUG;
    if (levelStr == "INFO") return INFO;
    if (levelStr == "WARNING") return WARNING;
    if (levelStr == "ERROR") return ERROR;
    return UNKNOWN;
}

void    harlFilter(const std::string& levelStr) {
    Harl harl;

    switch (getLevel(levelStr)) {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
            /*fallthrough*/
            // break を書かずに下の case へ流す（フォールスルー）
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            /*fallthrough*/
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            /*fallthrough*/
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
            /*fallthrough*/
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

void    Harl::_debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::_info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::_warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::_error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

