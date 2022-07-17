#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
#include <map>
#include <string>
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N, Q;
  string input;
  string query;
  // vector<string> tags;
  vector<string> queries;

  // process the first input. in case of the example " 4 3"
  getline(cin, input);
  stringstream ss{input};
  string times;
  getline(ss, times, ' ');
  N = stoi(times);
  getline(ss, times, ' ');
  Q = stoi(times);

  // save HRML
  vector<pair<string, string>> attr_val_vector{};
  map<std::string, vector<pair<string, string>>> HRML_map;
  for (auto i = 0; i < N; i++) {
    attr_val_vector.clear();

    getline(cin, input);


    // ignore the ending tags. assume input for this part is even number
    if (input[1] != '/') {
      input = input.substr(1, input.size() - 2);  // remove the first and the last charcter

      stringstream sstag{input};
      string w, tagname, attrname, val;
      sstag >> tagname;
      while (sstag >> attrname) {
        sstag >> w;  // should be the equal sign. ignored
        sstag >> val;
        std::pair<string, string> attr_val_pair{attrname, val};
        attr_val_vector.push_back(attr_val_pair);
      }
      // cout << "--> " << input << "--> " << tagname << " & " << attrname << " & " << val << endl;
      HRML_map[tagname] = attr_val_vector;
    }
  }

  // save Queries
  for (auto i = 0; i < Q; i++) {
    getline(cin, query);
    queries.push_back(query);
  }

  // Process Queries
  // split a query into two parts, tag part and attr part. ~ is between them
  // extract the last tag
  // search the tag with HRML_map
  // for loop attr_val_vector
  //  if the attr found in the pari's first field, cout << the value(the second)
  for (auto q : queries) {
    stringstream ssq{q};
    string tagpart, tag, attr, val;
    getline(ssq, tagpart, '~');
    getline(ssq, attr, '~');
    // cout << "tagpart is " << tagpart << " and attr_val_part is "
    //      << attr_val_part << endl;
    ssq.str("");
    ssq.clear();
    ssq.str(tagpart);
    while(getline(ssq,tag,'.')){
      // cout << "the tag is " << tag << endl;
    }

    val = "";
    for (auto v:HRML_map[tag]) {
      if (v.first == attr)
        val = v.second;

    }
    if (val=="")
      cout << "Not Found!" << endl;
    else {
      val.erase(remove(val.begin(), val.end(), '"'), val.end()); 
      cout << val << endl;
    }
  }
  return 0;
}
