#ifndef USER_H
#define USER_H
#include <string>

class User {

private:
  std::string firstName;
  std::string lastName;
  std::string email;
  std::string password;

public:
  User();
  User(const std::string &firstName, const std::string &lastName,
       const std::string &email, const std::string &password);

  std::string getFirstName();
  std::string getLastName();
  std::string getEmail();
  std::string getPassword();

  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);
  void setEmail(std::string email);
  void setPassword(std::string password);
};
#endif // !USER_H
