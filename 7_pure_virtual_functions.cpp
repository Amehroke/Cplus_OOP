#include <iostream>
using namespace std;


// Pure virtual functions are used to make it to where all derived classes must implement the same Method
// The base class does not define the method, but it does define the method as a pure virtual function

//Now instrument class is an abstract class, meaning it has atleast one pure virtual function
class instrument {
    public:
        // This is implementation of a pure virtual function
        virtual void Makesound() = 0;


};

class Accordion: public instrument {
    public:
        void Makesound(){
            cout << "Accordion makes sound" << endl;
        };
};

class piano: public instrument {
    public:
        void Makesound(){
            cout << "Piano makes sound" << endl;
        };
};


int main() {

    // This will not work, because the base class is an abstract class
    // instrument i;
    // i.Makesound();

    // This will call the most derived class function, due to the base class function being virtual
    instrument *i1 = new Accordion();
    // i1->Makesound();

    instrument *i2 = new piano();
    // i2->Makesound();

    instrument* instruments[2] = {i1, i2};

    for (int i = 0; i < 2; i++){
        instruments[i]->Makesound();
    }


    return 0;
}
