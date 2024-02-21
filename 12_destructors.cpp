#include <iostream>
using namespace std;

// Destructor is untilized when we need to reallocate memory or release resources

class Book {
    public:
        string Title; 
        string Author;
        // We need to use a pointer to allocate memory for the array of rates
        int* Rates; 
        int RateCounter; 

        // Constructor has no parameters or return type
        Book(string title, string author){
            Title = title;
            Author = author;
            cout << Title + "Book is Constructor" << endl;
            
            // We allocate memory for the array of rates
            RateCounter = 2; 
            Rates = new int[RateCounter];
            Rates[0] = 3;
            Rates[1] = 5;
        }

        // Destructor always has ~ in front of the class name, and has no parameters or return type
        ~Book(){
            cout << Title + "Book is destroyed" << endl;
            // We deallocate memory for the array of rates
            delete[] Rates;

            // We set the pointer to null to avoid dangling pointer
            Rates = nullptr;
        }
}; 


int main() {

    Book book1("Harry Potter", "JK Rowling");
    Book book2("Lord of the Rings", "Tolkein");
    Book book3 = book1; // This will call the copy constructor
    
    return 0;
}