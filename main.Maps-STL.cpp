#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string,int> scores;
    map<string,int>::iterator itr;
    string Ns,Ds,name;
    int Ni,Di, score;


    cin >> Ns;
    Ni = stoi(Ns);
    while (Ni--) {
      cin >> Ds >> name;
      Di = stoi(Ds);
    //   cout << Di << endl;
      switch (Di) {
        case 1:
            cin >> score;
            itr=scores.find(name); 
            if (itr == scores.end() )
                scores[name] = score;
            else
                scores[name] += score;
            break;
        case 2:
            scores.erase(name);
            break;
        case 3:
            cout << scores[name] << endl;
            break;
        default:
            break;
      }
    }
    return 0;
}



