#include <iostream>
using namespace std;

// Friend functions are not member functions, but they have access to the private members of the class.
// Use friend functions sparingly, as it breaks the encapsulation of the class. 
// Friend functions are not inherited.

class EqualateralTriangle{
    private:
        // How can we acess Circumference and Area from main, without use of getter & setters? 
        // We can use friend functions.
        float a; 
        float circumference;
        float area;

    public:
        void setA(float length){
            a = length;
            circumference = 3*a;
            area = (a * a * sqrt(3)) / 4;
        }

        // This declares the function PrintResults as a friend of the class Equalateral
        friend void PrintResults(EqualateralTriangle);

        // This declares the class Homework as a friend of the class Equalateral
        friend class Homework;
};

void PrintResults(EqualateralTriangle et){
    cout << "Circumference: " << et.circumference << endl;
    cout << "Area: " << et.area << endl;
}

class Homework{
    public:
        void PrintResults(EqualateralTriangle et){
            cout << "Circumference: " << et.circumference << endl;
            cout << "Area: " << et.area << endl;
        }
};


int main() {
    
    EqualateralTriangle et; 
    et.setA(3);
    
    PrintResults(et);
    
    Homework hw;
    hw.PrintResults(et);

    
    return 0;
}