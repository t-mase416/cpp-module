#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "Contact.hpp"

class PhoneBook{
    private:
        Contact contacts[8];
        int currentIndex;
        int contactCounts;
    public:
        PhoneBook();
        ~PhoneBook();

        void    addNewContact();
        void    searchContact();
};

#endif