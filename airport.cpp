#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

void inRange(map<string, int>, int, int);

int main(){
    ifstream fin;
    map <string, int> air;

    //opening file
    fin.open("210-final-1-SP26.txt");
    //error handling
    if (!fin) {
        //unbuffered version of cout -- w3school
        cerr << "Error opening file." << endl; 
        return 1;
    }

    string start;
    string dest;

    //while loop to read in air ports and count up number of times
    //each airport visited.
    while (fin >> start) {
        fin >> dest;
        //incrementing duplicate aiports by one to find frequency
        air[start]++; 
        air[dest]++;
    }

    //closing file
    fin.close();

    //range based for loop to print out map
    cout << "All airport traffic counts:\n";
    for (auto a : air) {
        cout << a.first << " " << a.second << endl;
    }

    int max = 0;
    //range based for loop iterates through all values and finds largest
    for (auto a : air) {
        if (a.second > max) {
            max = a.second;
        }
    }

    cout << "\nBusiest airport(s) with count " << max << ":\n";
    //incase there are ties, using another range based loop to print all 
    //airports that match max val
    for (auto a : air) {
        if (a.second == max) {
            cout << a.first << " " << a.second << endl;
        }
    }

    //driver for M3
    inRange(air, 5, 8);
    inRange(air, 9, 12);

    return 0;
}

void inRange(map<string, int> m, int lower, int upper){
    //using range based loop to check for values of map within range and printing
    cout << "\nAirports with traffic in range [" << lower << ", " << upper <<"]:\n";
    for (auto a : m){
        if (a.second <= upper && a.second >= lower){
            cout << a.first << " " << a.second << endl;
        }
    }

}
