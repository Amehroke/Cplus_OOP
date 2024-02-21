#include <iostream>
using namespace std;


// Abstraction is the concept of hiding the internal details and showing only the functionality.
// This is shown by creating a virtual function in the base class and then implementing it in the derived class.


// This is the base class that the user is going to use.
class Smartphone{
    public: 
        virtual void TakeASelfie() = 0;
        virtual void MakeACall() = 0;
};

// These are the classes that are going to be hidden from the user.
class Android : public Smartphone{
    public:
        void TakeASelfie(){
            cout << "Android Selfie" << endl;
        }

        void MakeACall(){
            cout << "Android Call" << endl;
        }
};
class Iphone : public Smartphone{
    public:
        void TakeASelfie(){
            cout << "Iphone Selfie" << endl;
        }

        void MakeACall(){
            cout << "Iphone Call" << endl;
        }
};

// The user only needs to know about the base class and not the derived classes.
int main() {
    
    Smartphone* S1 = new Android();
    S1->TakeASelfie();
    S1->MakeACall();

    Smartphone* S2 = new Iphone();
    S2->TakeASelfie();
    S2->MakeACall();

    return 0;
}
