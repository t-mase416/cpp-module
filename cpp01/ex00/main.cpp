#include "Zombie.hpp"

int main(){
    Zombie* z = newZombie("dynamicZombie");
    z->announce();
    randomChump("staticZombie");
    delete(z);
}