#include <iostream>
using namespace std;

// Destructor is untilized when we need to reallocate memory or release resources

class Book {
    public:
        string Title; 
        string Author;
        // We need to use a pointer to allocate memory for the array of rates
        float* Rates; 
        int RateCounter; 

        // Constructor has no parameters or return type
        Book(string title, string author){
            Title = title;
            Author = author;
            cout << Title + "Book is Constructor" << endl;
            
            // We allocate memory for the array of rates
            RateCounter = 2; 
            Rates = new float[RateCounter];
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


        //copy constructor
        Book(const Book& original){
            Title = original.Title;
            Author = original.Author;
            RateCounter = original.RateCounter;

            Rates = new float[RateCounter];
            for (int i = 0; i < RateCounter; i++){
                Rates[i] = original.Rates[i];
            }
            cout << Title + "Book is Copied" << endl;
        }; 
};  

void PrintBook(Book book){
    cout << "Title: " << book.Title << endl;
    cout << "Author: " << book.Author << endl;
    float sum = 0;
    for (int i = 0; i < book.RateCounter; i++){
        sum += book.Rates[i];
    }
    cout << "Average Rate: " << sum / book.RateCounter << endl;
}

int main() {

    Book book1("Harry Potter", "JK Rowling");
    Book book2("Lord of the Rings", "Tolkein");

    // Book book3(book2); // Copy constructor is called
    // Book book3 = book2; // Copy constructor is called same as above
    
    PrintBook(book1); // The copy constructor is called first, when we pass a object to a function
    PrintBook(book2);
    // PrintBook(book3);
    return 0;
}