#define MAXSIZE 350
#include <string>

struct CityAQrecordord {

    std::string city;
    std::string country;
    std::string airqual;
    std::string waterqual;
};

class AUList
{
public:

    AUList(); // Constructor

    void MakeEmpty();  // Returns the list to the empty state.

    bool IsFull() const; //Determines whether list is full. (Precondition -- list has been initialized).  Return value of "True" indicates class is full.

    int GetLength() const; //Determines the number of elements in list.

    void PutItem(CityAQrecordord); //Adds the item to the list.

    void ResetList();  //Initializes iterator's current position for an iteration through the list.

    CityAQrecordord GetNextItem(); //Gets the next element in the list.

    bool HasNextItem();

    void PrintList();  //Print all elements of the list in a readable format.



private:
    int length;
    CityAQrecordord ListItems[MAXSIZE];
    int currentPos;
};
