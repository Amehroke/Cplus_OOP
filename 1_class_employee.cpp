#include <iostream>
using namespace std;

class Employee {
    public:
        string name;
        string company;
        int age;

    void introduceYourself() {
        cout << "Name - " << name << endl;
        cout << "Company - " << company << endl;
        cout << "Age - " << age << endl;
    }
};


int main() {
    
    Employee employee1;
    employee1.name = "Saldina";
    employee1.company = "YT-CodeBeauty";
    employee1.age = 25;

    employee1.introduceYourself();


    Employee employee2;
    employee2.name = "Joe";
    employee2.company = "Amazon";
    employee2.age = 30;

    employee2.introduceYourself();

    return 0;
}