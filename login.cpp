#include "user.h"
#include <iostream>

int displayDashboard(User *&accounts, int &accountsLength, int &capacity);
void displayAccounts(User *accounts, int accountsLength);
void appendUser(User *&accounts, User &user, int &accountsLength,
                int &capacity);
void displayLoginPage(User *accounts, int accountsLength);
void displayRegisterPage(User *&accounts, int &accountsLength, int &capacity);

int main() {
  int choice = 0;
  User *accounts = NULL;
  int accountsLength = 0;
  int capacity = 0;

  do {
    system("cls");
    choice = displayDashboard(accounts, accountsLength, capacity);
  } while (choice != 4);

  return 0;
}

int displayDashboard(User *&accounts, int &accountsLength, int &capacity) {
  int choice = 0;
  char random = 0;
  std::cout << "Menu:" << std::endl;
  std::cout << "1. Login" << std::endl;
  std::cout << "2. Register" << std::endl;
  std::cout << "3. Display Accounts" << std::endl; // Added this option
  std::cout << "4. Exit" << std::endl;             // Added exit option
  std::cout << "Choice: ";
  std::cin >> choice;

  switch (choice) {
  case 1:
    displayLoginPage(accounts, accountsLength);
    break;
  case 2:
    displayRegisterPage(accounts, accountsLength, capacity);
    break;
  case 3:
    displayAccounts(accounts, accountsLength);
    break;
  case 4:
    std::cout << "Exiting..." << std::endl;
    break;
  default:
    std::cout << "Invalid input." << std::endl;
    break;
  }
  std::cin >> random;
  return choice; // Returning the choice to determine if the loop should
                 // continue
}

void displayAccounts(User *accounts, int accountsLength) {
  if (accountsLength == 0) {
    std::cout << "No accounts available." << std::endl;
    return;
  }

  for (int i = 0; i < accountsLength; i++) {
    std::cout << accounts[i].getEmail() << ", " << accounts[i].getPassword()
              << std::endl;
  }
}

void displayLoginPage(User *accounts, int accountsLength) {
  std::string email;
  std::string password;

  std::cout << "Email: ";
  std::cin >> email;

  std::cout << "Password: ";
  std::cin >> password;

  std::cout << "Email: " << email << "Password: " << password << std::endl;

  bool found = false;

  for (int i = 0; i < accountsLength; i++) {
    if (accounts[i].getEmail() == email &&
        accounts[i].getPassword() == password) {
      found = true;
      break;
    }
    std::cout << accounts[i].getEmail() << "," << accounts[i].getPassword()
              << std::endl;
  }

  if (found) {
    std::cout << "You have successfully logged in." << std::endl;
  } else {
    std::cout << "Account not found." << std::endl;
  }
}

void displayRegisterPage(User *&accounts, int &accountsLength, int &capacity) {
  std::string firstName;
  std::string lastName;
  std::string email;
  std::string password;
  std::string rePassword;

  std::cout << "First Name: ";
  std::cin >> firstName;

  std::cout << "Last Name: ";
  std::cin >> lastName;

  std::cout << "Email: ";
  std::cin >> email;

  std::cout << "Password: ";
  std::cin >> password;

  std::cout << "Repeat Password: ";
  std::cin >> rePassword;

  if (password == rePassword) {
    User newUser = User(firstName, lastName, email, password);
    appendUser(accounts, newUser, accountsLength, capacity);
    std::cout << "Account has been successfully registered!." << std::endl;
  } else {
    std::cout << "Passwords are not the same." << std::endl;
  }
}

void appendUser(User *&accounts, User &newUser, int &accountsLength,
                int &capacity) {
  if (accountsLength == capacity) {
    int newCapacity = capacity == 0 ? 1 : capacity * 2;
    User *newAccounts = new User[newCapacity];

    for (int i = 0; i < accountsLength; i++) {
      newAccounts[i] = accounts[i];
    }

    delete[] accounts;
    accounts = newAccounts;
    capacity = newCapacity;
  }
  accounts[accountsLength++] = newUser;
  std::cout << accounts[accountsLength - 1].getEmail() << ", "
            << accounts[accountsLength - 1].getPassword() << std::endl;
}
