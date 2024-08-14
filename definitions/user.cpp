#include "../headers/user.h"

User::User() : firstName(""), lastName(""), email(""), password("") {}

User::User(const std::string &firstName, const std::string &lastName,
           const std::string &email, const std::string &password)
    : firstName(firstName), lastName(lastName), email(email),
      password(password) {}

std::string User::getFirstName() { return firstName; }

std::string User::getLastName() { return lastName; }

std::string User::getEmail() { return email; }

std::string User::getPassword() { return password; }

void User::setFirstName(std::string firstName) { this->firstName = firstName; }

void User::setLastName(std::string lastName) { this->lastName = lastName; }

void User::setEmail(std::string email) { this->email = email; }

void User::setPassword(std::string password) { this->password = password; }
