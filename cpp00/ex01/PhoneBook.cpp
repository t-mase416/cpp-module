#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    currentIndex = 0;
    contactCounts = 0;
}

PhoneBook::~PhoneBook() {
}

//ただ入力を受けとってそれをチェックするだけの関数、戻り値はstring,、引数は受け取りたい入力
std::string getValidInput(std::string prompt){
    std::string line = "";
    while (line.empty()){
        std::cout << prompt;
        std::getline(std::cin, line);
    }
    return (line);
}

void    PhoneBook::addNewContact(){
//FirstNameからsecretまで計5回入力を受け取る、その後indexを増やし、カウントも増やす
    contacts[currentIndex].setFirstName(getValidInput("First Name: "));
    contacts[currentIndex].setLastName(getValidInput("Last Name: "));
    contacts[currentIndex].setNickname(getValidInput("Nickname: "));
    contacts[currentIndex].setPhoneNumber(getValidInput("Phone Number: "));
    contacts[currentIndex].setDarkestSecret(getValidInput("Darkest Secret: "));
    if (currentIndex < 7)
        currentIndex++;
    else
        currentIndex = 0;
    if (contactCounts < 8)
        contactCounts++;
}

void    PhoneBook::searchContact(){
//配列の情報をもとに簡易的な情報の表示（displaySummary()）をcountの数だけ繰り返し行い、
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < contactCounts; i++) {
        contacts[i].displaySummary(i);
    }
//その後特定のindexを受け取る、それに応じて該当の配列のすべての情報を表示
    std::string input;
    std::cout << "Enter index to display: ";
    std::getline(std::cin, input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int index = input[0] - '0';
        if (index < contactCounts) {
            contacts[index].displayDetails();
        } else {
            std::cout << "Invalid indes: No contact at this index." << std::endl;
        }
    } else {
        std::cout << "Invalid input : Please enter a valid number." << std::endl;
    }
}