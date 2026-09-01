#include "replace.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
    if (ac != 4)
        return (1);
    FileReplacer replacer(av[1], av[2], av[3]);
    if (!replacer.execute())
        return (1);
    return (0);
}
