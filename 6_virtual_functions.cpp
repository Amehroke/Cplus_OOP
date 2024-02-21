#include <iostream>
using namespace std;

// Virtual functions will let the most derived class function be called 
// when a base class pointer is used to call the function
class instrument {
    public:
        virtual void Makesound(){
            cout << "Instrument makes sound" << endl;
        };

};

class Accordion: public instrument {
    public:
        void Makesound(){
            cout << "Accordion makes sound" << endl;
        };
};


int main() {
    instrument i;
    i.Makesound();

    // This will call the most derived class function, due to the base class function being virtual
    instrument *i1 = new Accordion();
    i1->Makesound();


    return 0;
}