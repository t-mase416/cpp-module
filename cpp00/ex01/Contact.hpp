#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        ~Contact();
        //新しい連絡先を追加するための関数
        void    setFirstName(std::string name);
        void    setLastName(std::string name);
        void    setNickname(std::string name);
        void    setPhoneNumber(std::string number);
        void    setDarkestSecret(std::string secret);
        //検索用に情報を表示するための関数
        void    displaySummary(int index);
        void    displayDetails();
};


#endif