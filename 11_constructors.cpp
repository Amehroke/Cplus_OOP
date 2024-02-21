#include <iostream>
using namespace std;


class User{
    public:
        string Firstname;
        string Lastname;
        int Age;
        string Email;
        // Default Constructor given by C++ intializes the object with default values usually 0 or empty

        // Default Constructor, once you define a constructor, the default constructor given by c++ is no longer available
        User(string firstname, string lastname, int age){
            Firstname = "John";
            Lastname = "Doe";
            Age = 0;
            Email = firstname + lastname + "@gmail.com";
        }

        // Constructor
        User(string firstname, string lastname, int age){
            Firstname = firstname;
            Lastname = lastname;
            Age = age;
            Email = firstname + lastname + "@gmail.com";
        }

};

int main() {

    User user2(); // Uses Default Constructor when no parameters are passed
    User user1("Jimmy", "Smith", 25); // Uses Constructor when parameters are passed

    return 0;
}