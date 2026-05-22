#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;
    map <string, int> air;

    //opening file
    fin.open("210-final-1-SP26.txt");
    //error handling
    if (!fin) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string start;
    string dest;

    //while loop to read in air ports and count up number of times
    //each airport visited.
    while (fin >> start) {
        fin >> dest;
        air[start]++;
        air[dest]++;
    }
    //range based for loop to print out map
    for (auto a : air) {
        cout << a.first << " " << a.second << endl;
    }



    //closing file
    fin.close();
    return 0;
}