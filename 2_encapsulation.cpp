#include <iostream>
using namespace std;

// Rules for encapsulation:
// 1. All the class members should be private
// 2. Each member should be accessed only through a function (getters and setters)

// Setter and getter methods are used to access private members of a class

class Employee {
    private:
        string Name;
        string Company;
        int Age;


    public:
        // setter for setting name 
        void setName(string name){
            Name = name;
        }

        // getter for getting name
        string getName(){
            return Name;
        }

        // setter for setting company
        void setCompany(string company){
            Company = company;
        }

        // getter for getting company
        string getCompany(){
            return Company;
        }

        // setter for setting age
        void setAge(int age){
            if(age >= 18){ //we can add more conditions now do to encapsulation
                Age = age;
            }
        }

        // getter for getting age
        int getAge(){
            return Age;
        }

        void introduceYourself() {
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }

        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            if(age >= 18){ //we can add more conditions now do to encapsulation
                Age = age;
            }
            else{
                cout << name << " ,You are not allowed to work here" << endl;
            }
        }
};


int main() {
    
    Employee employee1("Saldina", "YT-CodeBeauty", 25);
    employee1.introduceYourself();

    Employee employee2("Joe", "Amazon", 30);
    employee2.introduceYourself();

    // employee1.Name = "Rick"; // This will not work because Name is private 
    
    employee1.setAge(30);
    cout << employee1.getName() << " is " << employee1.getAge() << endl;

    employee1.setAge(17); // This will not work because of the condition in the setter

    Employee employee3("Rick", "Cart", 15); // This will not work because of the condition in the constructor
    return 0;
}