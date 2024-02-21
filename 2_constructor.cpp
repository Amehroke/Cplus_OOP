#include <iostream>
using namespace std;

// Rules for constructors:
// 1. It mostly has to be public
// 2. It has the same name as the class
// 3. It can't have a return type


class Employee {
    private:
      

    public:
        string Name;
        string Company;
        int Age;

    void introduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};


int main() {
    
    Employee employee1("Saldina", "YT-CodeBeauty", 25);
    employee1.introduceYourself();

    Employee employee2("Joe", "Amazon", 30);
    employee2.introduceYourself();

    return 0;
}