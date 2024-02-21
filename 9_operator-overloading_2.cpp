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

        // This is used to overload the == operator for function 5
        // we use const to make sure that the object is not changed in the function, this is so we dont get compile errors
        bool operator == (const YouTubeChannel& channel) const{ //we use bool due to we just want to return T or F if the names are the same
            return this->Name == channel.Name;
        }

};

//Function 1
ostream& operator << (ostream& COUT, YouTubeChannel& yt){   //We use & to pass the object by reference so that we don't make a copy of the object.
    COUT << "Name: " << yt.Name << endl;
    COUT << "Subscribers: " << yt.SubscribersCount << endl;
    return COUT;
}


class MyCollection {
    public:
        list <YouTubeChannel> myChannels;
        //Function 2 Memeber function for overloading the += operator
        void operator += (YouTubeChannel& channel){
            this->myChannels.push_back(channel);
        }

        //Function 3 Memeber function for overloading the -= operator
        void operator -= (YouTubeChannel& channel){ //this will not work due to the compare == operator in remove function
            this->myChannels.remove(channel);       // we need to overload the == operator, due to it doesnt know how to compare the objects (channel)
        }                                           // == operator is overloaded in the YouTubeChannel class
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

    MyCollection myCollection;
    
    //function 2
    myCollection += yt1; 
    myCollection += yt2;

    //function 4
    cout << myCollection; 

    //function 3
    myCollection -= yt1; 

    //function 4
    cout << myCollection;

    return 0;
}