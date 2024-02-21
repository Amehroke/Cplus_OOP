#include <iostream>
using namespace std;

// Rules for abstraction:
// 1. It is used to hide the complexity of the system and showing only the necessary details to the user

// This is an abstract class, and it is used to hide the implementation details from the user
class AbsractEmployee {
   virtual void AskForPromotion() = 0;
};


// Employee class is inheriting the abstract class and implementing the pure virtual function
class Employee: AbsractEmployee{
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

        void AskForPromotion(){
            if(Age > 30){
                cout << Name << " got promoted!" << endl;
            }
            else{
                cout << Name << " ,Sorry no promotion for you" << endl;
            }
        }
};


int main() {
    
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    Employee employee2 = Employee("Joe", "Amazon", 33);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    return 0;
}