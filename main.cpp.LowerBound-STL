#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> vec;
    string N,data;
    cin >> N;
    for (size_t i = 0; i < stoi(N); i++)
    {
      cin >> data;
      vec.emplace_back(stoi(data));
    }

  vector<int>::iterator low,up;
//   low=lower_bound (vec.begin(), vec.end(), 20); 
//   up= upper_bound (vec.begin(), vec.end(), 20); 
  

    cin >> N;
    for (size_t i = 0; i < stoi(N); i++)
    {
      cin >> data;
      low=lower_bound (vec.begin(), vec.end(), stoi(data));
    //   cout << "low is : " << (low- vec.begin()) << " & " << *low << endl;
      if (*low == stoi(data)) {
        cout << "Yes " << (low- vec.begin()+1) << endl;
      } else {
        cout << "No " << (low- vec.begin()+1) << endl;
      }
      
    }

    return 0;
}
