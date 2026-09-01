#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

//メンバ関数はデフォルトで呼び出し元を指すthisポインタがセットされている
void    Zombie::setname(std::string name) {
    this->_name = name;
}

void    Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}