#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setFirstName(std::string name)
{
    firstName = name;
}

void Contact::setLastName(std::string name)
{
    lastName = name;
}

void Contact::setNickname(std::string name)
{
    nickname = name;
}

void Contact::setPhoneNumber(std::string number)
{
    phoneNumber = number;
}

void Contact::setDarkestSecret(std::string secret)
{
    darkestSecret = secret;
}

std::string formatField(std::string str)
{
    if (str.length() > 10)
    {
        return (str.substr(0, 9) + ".");
    }
    return (str);
}

void Contact::displaySummary(int index)
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << formatField(firstName) << "|"
              << std::setw(10) << formatField(lastName) << "|"
              << std::setw(10) << formatField(nickname) << std::endl;
}

void Contact::displayDetails()
{
    std::cout << "First Name:     " << firstName << std::endl;
    std::cout << "Last Name:      " << lastName << std::endl;
    std::cout << "Nickname:       " << nickname << std::endl;
    std::cout << "Phone Number:   " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
