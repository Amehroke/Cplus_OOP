#include <iostream>
#include <string>
#include <list>

using namespace std;

// Operator overloading is a concept of using the same operator to perform different operations based on the context.

class YouTubeChannel{
    public:
        string Name;
        int SubscribersCount;

        YouTubeChannel(string name, int subscribersCount){
            Name = name;
            SubscribersCount = subscribersCount;
        }

};

// This is to overload Library functions. ostream is a library function. #include <iostream>

// Funciton 1 
// void operator << (ostream& COUT, YouTubeChannel& yt){   //We use & to pass the object by reference so that we don't make a copy of the object.
//     COUT << "Name: " << yt.Name << endl;
//     COUT << "Subscribers: " << yt.SubscribersCount << endl;
// }

//Function 2
ostream& operator << (ostream& COUT, YouTubeChannel& yt){   //We use & to pass the object by reference so that we don't make a copy of the object.
    COUT << "Name: " << yt.Name << endl;
    COUT << "Subscribers: " << yt.SubscribersCount << endl;
    return COUT;
}


class MyCollection {
    public:
        list <YouTubeChannel> myChannels;
        //Function 3 Memeber function for overloading the += operator
        void operator += (YouTubeChannel& channel){
            this->myChannels.push_back(channel);
        }
};

//Function 4
ostream& operator << (ostream& COUT, MyCollection& myCollection){
    COUT << "My Collection: " << endl;
    for (YouTubeChannel ytChannel : myCollection.myChannels){
        COUT << ytChannel << endl;
    }
    return COUT;
}

int main() {
    
    YouTubeChannel yt1("CodeBeauty", 75000);
    YouTubeChannel yt2("AmySings", 250000);

    // cout << yt1 << endl; // This will give an error because the << operator is not defined for the YouTubeChannel class.

    //After defining the << operator, we can use it to print the object. (Function 1)
    cout << yt1;

    // cout << yt1 << yt2; // This will not work due to the operator not returning ostream object.

    //After returning the ostream object, we can use the operator to print multiple objects. (Function 2)
    cout << yt1 << yt2;

    //Another way to call overloaded operator
    // operator << (cout, yt1); 

    MyCollection myCollection;
    // myCollection += yt1; // Here we are trying to overload the += operator. (Function 3)
    myCollection += yt1; 
    myCollection += yt2;

    //function 4
    cout << myCollection; 

    return 0;
}