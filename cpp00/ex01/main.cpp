#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main()
{
    /*Phonebookクラスのインスタンスを生成
    開始メッセージ
    以下をループ（EXITでのみ抜ける）
    getlineの受付
    （ADD, SEARCH, EXITそれぞれの処理記述）
     */
    PhoneBook phonebook;
    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT) : ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF detected. Exiting..." << std::endl;
            break;
        }
        if (command == "ADD") {
            phonebook.addNewContact();
        }
        else if (command == "SEARCH") {
            phonebook.searchContact();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command. Enter (ADD, SEARCH, EXIT)." << std::endl;
        }
    }
    return (0);
}