#include <iostream>
#include <string>

int main()
{
    std::string prompt = "First Name : ";
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    std::cout << line << std::endl;
}