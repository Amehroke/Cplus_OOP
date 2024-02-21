#include <iostream>
using namespace std;

// Rules for polymorphism:
// 1. It is used to represent the same method in different forms




// This is an abstract class, and it is used to hide the implementation details from the user
class AbsractEmployee {
   virtual void AskForPromotion() = 0;
};

class Employee: AbsractEmployee{
    // private members are not accessible outside the class
    private:
        string Company;
        int Age;

    //protected members are accessible in the derived class
    protected: 
        string Name;

    // public members are accessible anywhere
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

        //when a function is declared as virtual in the base class, it is expected to be redefined in the derived class
        virtual void Work(){
            cout << Name << " is checking email, task backlog, performing tasks..." << endl;
        }
};

// This is a derived class, and it is used to inherit the members of the base class
//Developer is the child class of the public side of Employee class
class Developer:public Employee{
    public: 
        string FavProgrammingLanguage;

        // constructor for Developer, we pass the name, company, age to Employee constructor
        Developer(string name, string company, int age, string favProgrammingLanguage)
            : Employee(name, company, age)
        {
            FavProgrammingLanguage = favProgrammingLanguage;

        }

        void FixBug(){
            //using getName() and Name to access the Name from the base class which is public
            cout << getName() << " fixed bug using " << FavProgrammingLanguage << endl;

            //using Name to access the Name from the base class which is protected
            cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;

        } 

        void Work(){
            cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl;
        }

         
}; 

// This is a derived class, and it is used to inherit the members of the base class
class Teacher: public Employee{
    public:
        string Subject;

        void prepareLesson(){
            cout << Name << " is preparing " << Subject << " lesson" << endl;
        }


        Teacher(string name, string company, int age, string subject)
            :Employee(name, company, age)
        {
            Subject = subject;
        }

        void Work(){
            cout << Name << " is teaching " << Subject << endl;
        }

};




int main() {

    Developer D = Developer("Sunny", "YT-CodeBeauty", 25, "C++");
    Teacher T = Teacher("Frank", "Cool School", 35, "History");

    D.Work();
    T.Work();

    // The most common use of polymorphism is when a parent class reference ...
    // is used to refer to a child class object

    Employee* e1 = &D;
    Employee* e2 = &T;
    
    e1->Work();
    e2->Work();


    return 0;
}  