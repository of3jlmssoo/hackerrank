#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <memory>
using namespace std;

struct Node {
  Node* next;
  Node* prev;
  int value;
  int key;
  Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
 protected:
  map<int, Node*> mp;              // map the key to the node in the linked list
  int cp;                          // capacity
  Node* tail;                      // double linked list tail pointer
  Node* head;                      // double linked list head pointer
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;        // get function
};

class LRUCache : Cache {
 private:
  // Node* nodeptr{nullptr};
  Node* nodeptr{nullptr};
  int capacity;
  int num{0};
  Node* current;

 public:
  LRUCache(int capacity) : capacity(capacity){};

  void delete_last_node() {
    Node* tmpptr = nodeptr;
    while (tmpptr->next) {
      tmpptr = tmpptr->next;
    }
    tmpptr->prev->next = nullptr;
    delete tmpptr;
    num--;
  }
  /* if already full capacity set the new node to the front and delete the last one */
  void set(int key, int value) {
    Node* tmpptr = nodeptr;
    while (tmpptr and tmpptr->next and tmpptr->key != key) {
      tmpptr = tmpptr->next;
    }

    if (tmpptr and tmpptr->key == key) {
      tmpptr->value = value;
      return;
    }

    current = new Node(key, value);
    num++;
    // unique_ptr<Node> current = make_unique<Node>(key, value);
    if (nodeptr) {
      current->next = nodeptr;
      nodeptr->prev = current;
    }
    nodeptr = current;
    if (num > capacity) {
      delete_last_node();
    }
  };
  void list_node_in_reverse1() {
    // cout << num << " nodes exist in the list" << endl;
    Node* tmpptr = nodeptr;
    for (size_t i = 0; i < num - 1; i++) {
      tmpptr = tmpptr->next;
    }
    // cout << "the key and the value of the last node " << tmpptr->key << " & " << tmpptr->value << endl << endl;
    for (size_t i = num; i > 0; i--) {
      cout << tmpptr->key << " & " << tmpptr->value << endl;
      tmpptr = tmpptr->prev;
    }
    cout << endl;
  }

  void list_node_in_reverse2() {
    Node* tmpptr = nodeptr;
    while (tmpptr->next) {
      tmpptr = tmpptr->next;
    }
    while (tmpptr->prev) {
      cout << tmpptr->key << " & " << tmpptr->value << endl;
      tmpptr = tmpptr->prev;
    }
    cout << tmpptr->key << " & " << tmpptr->value << endl;
    cout << endl;
  }

  void move_to_top(Node* tmpptr) {
    // if top
    if (tmpptr == nodeptr) return;

    // if last
    if (tmpptr->next == nullptr) {
      // the second to last Node
      tmpptr->prev->next = nullptr;

      // the frist node
      nodeptr->prev = tmpptr;
      tmpptr->next = nodeptr;

      nodeptr = tmpptr;
      nodeptr->prev = nullptr;
      return;
    }

    // if middle
    tmpptr->prev->next = tmpptr->next;
    tmpptr->next->prev = tmpptr->prev;

    // the frist node
    nodeptr->prev = tmpptr;
    tmpptr->next = nodeptr;

    nodeptr = tmpptr;
    nodeptr->prev = nullptr;
    return;
  }

  int get(int key) {
    Node* tmpptr = nodeptr;
    int result{-1};
    
    if (nodeptr==nullptr) {
      result = -1;
      return result;
    }



    while (tmpptr->next and tmpptr->key != key) {
      tmpptr = tmpptr->next;
    }
    if (tmpptr->key == key) {
      result = tmpptr->value;
    } else {
      result = -1;
    }

    move_to_top(tmpptr);

    return result;
  };
};

int main() {
  int n, capacity, i;

  capacity = 3;
  LRUCache l(capacity);
  // l.get(3);
  // l.set(1, 123);
  // l.set(2, 234);
  // l.set(3, 345);
  // // l.list_node_in_reverse1();
  // l.list_node_in_reverse2();
  // l.set(4, 456);
  // // l.list_node_in_reverse1();
  // l.list_node_in_reverse2();
  // l.set(4, 456789);
  // l.list_node_in_reverse2();
  // cout << "get(3) " << l.get(3) << endl;
  // l.list_node_in_reverse2();
  // cout << "get(2) " << l.get(2) << endl;
  // l.list_node_in_reverse2();
  // cout << "get(2) " << l.get(2) << endl;
  // l.list_node_in_reverse2();

  // cin >> n >> capacity;  // n lines and cache capacity。例題ではcapacity == 1
  // LRUCache l(capacity);
  // for (i = 0; i < n; i++) {
  //   string command;
  //   cin >> command;
  //   if (command == "get") {
  //     int key;
  //     cin >> key;
  //     cout << l.get(key) << endl;
  //   } else if (command == "set") {
  //     int key, value;
  //     cin >> key >> value;
  //     l.set(key, value);
  //   }
  // }





  return 0;
}

/*



*/