#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  fstream newfile;

  newfile.open("../abstractclass.exercise.txt", ios::in);  // open a file to perform read operation using file object
  if (newfile.is_open()) {                                 // checking whether the file is open
    string tp;
    while (getline(newfile, tp)) {  // read data from file object and put it into string.
      stringstream ss;
      string setget;
      string key, value;
      ss << tp;
      ss >> setget;
      if (setget == "set") {
        ss >> key >> value;
        cout << "l.set(" << key << "," << value << ")" << endl;
      } else if (setget == "get") {
        ss >> key;
        cout << "l.get(" << key << ")" << endl;
      }

      // cout << tp << "\n";           // print the data of the string
    }
    newfile.close();  // close the file object.
  }
  return 0;
}
