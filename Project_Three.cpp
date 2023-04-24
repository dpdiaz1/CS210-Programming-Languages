// Diana Diaz - CS 210 Project Three

#include <iostream>
#include <fstream>
#include <map>
using namespace std;
class Grocery {   // defining class for the program
private:   // private data members
    map<string, int> produceList;   // declaring map name produceList
public:   // public data members
    void displayMenu();
    void displayHistogram();
    void loadDataFile();
    void printMap();
    int getItemFrequency(const string& dataStore);
    map<string, int> getAllItemFrequency();
    void addItem(string item);
    void saveDataFile();
};

// call each method that is listed under the public data members
void Grocery::loadDataFile() {  // loadDataFile from Grocery class
    ifstream inFS;  
    inFS.open("Project_Three_Input_File.txt");   // open input file
    if (!inFS.is_open()) {   // check if input file opened or not
        cout << "Could not open file Project_Three_Input_File.txt" << endl;  // user  validation if file was not able to open
        return;
    }
    string tmp;
    while (inFS >> tmp) {  // while input is open, add each item read to "tmp"
        addItem(tmp); // call the method to add item into the map
    }
    inFS.close();   // close file
}

void Grocery::addItem(string item) {   // method addItem from Grocery list
    produceList[item]++;   // save each item from input file to producelist
}

int Grocery::getItemFrequency(const string& dataStore) {   //  method getItemFrequency from Grocery list
    return  produceList[dataStore];   // save the frequency of each item to producelist, dataStore vector
}

map<string, int> Grocery::getAllItemFrequency() {   //  map and method getAllItemFrequency from Grocery list
    return  produceList;   
}

void Grocery::saveDataFile() {   //  method saveDataFile from Grocery list
    ofstream outFS;
    outFS.open("Project_Three_Output_File.txt");   // open output file
        if (!outFS.is_open()) {   // check if output file has not opened
            cout << "Could not open file Project_Three_Output_File.txt" << endl;   // user validation if file is not open
            return;
        }

        for (auto& p1 : produceList) {   // if file is open, 
            outFS << p1.first << " " << p1.second << endl;   // add items to output file as map- key, space, value
        }


    outFS.close();   // close output file
}

void Grocery::displayMenu() {   //  method displayMenu from Grocery list
    int userInput;
    string dataStore;

    do {   // user menu
        cout << "1. Search List " << endl;
        cout << "2. Print List" << endl;
        cout << "3. Print Frequency" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Please select a menu option 1-4" << endl;
        //cout << "Enter item name:" << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:   // menu option 1
            cout << "Enter the item to search:";
            cin >> dataStore;  // search item from dataStore
            cout << "The frequency of " << dataStore << " is " << getItemFrequency(dataStore) << endl;
            break;

        case 2:   // menu option 2
            printMap();   
            break;

        case 3:   // menu option 3
            displayHistogram();   // item frequency as a symbol
            break;

        case 4:   // menu option 4
            cout << "Exiting Program...";
            break;
        default:
            cout << "Invalid choice!" << endl;   // menu option validation to catch an invalid input
            break;

        }
    } while (userInput != 4);

}


void Grocery::displayHistogram() {   //  method displayHistogram from Grocery list
    for (auto pl : produceList)
    {
        cout << pl.first << " ";
        for (int i = 1; i <= pl.second; i++)
            cout << "*";
        cout << endl;
    }
}

void Grocery::printMap() {   //  method printMap from Grocery list
    for (auto pl : produceList)   // map name produceList
        cout << pl.first << " " << pl.second << endl;   // map is printed as key, space, value

}


int main() {  

    Grocery obj;   // call Grocery class
    obj.loadDataFile();  // load the data file
    obj.displayMenu();  // It will display the menu     

    return 0;
}

