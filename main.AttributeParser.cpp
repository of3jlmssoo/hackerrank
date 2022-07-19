#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
using namespace std;
#include <map>
#include <string>
#include <typeinfo>
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N, Q;
  string input;
  string query;
  // vector<string> tags;
  vector<string> queries;

  // process the first input. in case of the example "4 3" 4 to N, 3 to Q
  getline(cin, input);
  stringstream ss{input};
  string times;
  getline(ss, times, ' ');
  N = stoi(times);
  getline(ss, times, ' ');
  Q = stoi(times);

  // save HRML
  // pair<string, string> attr_val_pair;                               // name, name1
  vector<pair<string, string>> attr_val_vec;                           // (name, name1) (val, 3)
  map<string, vector<pair<string, string>>> tag_vec_map;               // b : (name, name1) (val, 3)
  vector<map<string, vector<pair<string, string>>>> tag_q;             // a b      or      A C D E
  vector<vector<map<string, vector<pair<string, string>>>>> HRML_vec;  // (a b) (A C D E)
  auto num_ele{0};
  for (int i{0}; i < N; i++) {
    attr_val_vec.clear();

    getline(cin, input);

    if (input[1] != '/') {
      input = input.substr(1, input.size() - 2);  // remove the first and the last charcter, "<" and ">"

      stringstream sstag{input};
      string w, tagname, attrname, val;
      sstag >> tagname;
      while (sstag >> attrname) {
        sstag >> w;  // should be the equal sign. ignored
        sstag >> val;
        std::pair<string, string> attr_val_pair{attrname, val};

        attr_val_vec.push_back(attr_val_pair);
      }
      tag_vec_map[tagname] = attr_val_vec;
      tag_q.push_back(tag_vec_map);

      tag_vec_map.clear();
      attr_val_vec.clear();

    } else {
      // the end tag processing
      // TODO: Not always
      if (tag_q.size() > num_ele) HRML_vec.push_back(tag_q);

      // do not clear the vector itself but erase the last element of the vector
      // tag_q.clear();
      tag_q.erase(tag_q.end() - 1);
      num_ele = tag_q.size();
    }
  }

  // save Queries
  for (auto i = 0; i < Q; i++) {
    getline(cin, query);
    queries.push_back(query);
  }

  // Process Queries

  for (auto q : queries) {
    stringstream ssq{q};
    string tagpart, tag, attr, val;
    getline(ssq, tagpart, '~');
    getline(ssq, attr, '~');
    ssq.str("");
    ssq.clear();
    ssq.str(tagpart);
    bool is_same{true};
    bool found{false};
    string result{""};
    vector<string> q_tags;
    while (getline(ssq, tag, '.')) {
      q_tags.push_back(tag);
    }

    // q_tags.clear();
    // q_tags.push_back("tag2");
    // q_tags.push_back("tag4");

    // q_tags.clear();
    // q_tags.push_back("tag6");
    // q_tags.push_back("tag8");

    // q_tags.clear();
    // q_tags.push_back("tag6");
    // q_tags.push_back("tag8");
    // q_tags.push_back("ntag");

    // q_tags.clear();
    // q_tags.push_back("tag6");
    // q_tags.push_back("tag8");
    // q_tags.push_back("ntag");
    // q_tags.push_back("nvtag");

    // q_tags.clear();
    // q_tags.push_back("tag6");
    // q_tags.push_back("tag8");
    // q_tags.push_back("nvtag");

    // q_tags.clear();
    // q_tags.push_back("radomtag");

    // q_tags.clear();
    // q_tags.push_back("tag283");
    // q_tags.push_back("tag21");

    // auto same_position{-1};
    for (auto vec1 : HRML_vec) {
      size_t last_index{0};
      if (q_tags.size() <= vec1.size()) {
        for (size_t i = 0; i < q_tags.size(); i++) {
          if (vec1.at(i).count(q_tags.at(i))) {  // vec1.at(i) is a map
            // cout << "--> " << q_tags.at(i) << " found!" << endl;
            last_index = i;
          } else {
            is_same = false;
          }
        }
        // cout << "the result is " << is_same << " " << typeid(vec1.at(last_index)).name() << endl;
        // cout << "the result is " << is_same << " " << vec1.at(last_index).count(q_tags.at(last_index)) << endl;
        if (is_same) {
          for (auto inside_vec : vec1.at(last_index)[q_tags.at(last_index)]) {
            // cout << inside_vec.first << " " << inside_vec.second << endl;
            if (attr == inside_vec.first) {
              found = true;
              result = inside_vec.second;
            }
          }
        }
      }
      is_same = true;
    }
    if (found) {
      result.erase(remove(result.begin(), result.end(), '"'), result.end());
      cout << result << endl;
    } else {
      cout << "Not Found!" << endl;
    }
    found = false;
    result = "";
  }
  return 0;
}
