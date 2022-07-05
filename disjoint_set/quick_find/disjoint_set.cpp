#include <iostream>
#include <vector>

using namespace std;

class Disjoint {
  public:
  /*
    @Instantiates the disjoint set
    Each node's root node is itself during initial construction
   */
  Disjoint(int size) : roots(size) {
    for(int i=0; i<size; i++) {
      roots[i] = i;
    }
  }
  /*
    @Returns the root of a given node in the set
  */
  int find(int x) {
    return roots[x];
  }
  /*
    @Unions two vertices and makes their root nodes the same
   */
  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if(rootX != rootY) {
      for (int i = 0; i < roots.size(); i++) {
        if (roots[i] == rootY) {
          roots[i] = rootX;
        }
      }
    }
  }

  bool connected(int x, int y) {
    return find(x) == find(y);
  }

  void print() {
    for (int i = 0; i < roots.size(); i++) {
      cout << roots[i] << " ";
    }
  }

  private:
  vector<int> roots;
};


int main() {
  Disjoint ds(10);
  ds.unionSet(1, 2);
  ds.unionSet(2, 5);
  ds.unionSet(5, 6);
  ds.unionSet(6, 7);
  ds.unionSet(3, 8);
  ds.unionSet(8, 9);

  cout << ds.connected(1, 5) << endl;
  cout << ds.connected(5, 7) << endl;
  cout << ds.connected(4, 9) << endl;

  ds.unionSet(9, 4);
  cout << ds.connected(4, 9) << endl;

  ds.print();

  cout << "Testing C++ constructors" << endl;

  ds = Disjoint(8);
  ds.unionSet(1, 2);
  ds.unionSet(2, 5);
  ds.unionSet(5, 6);
  ds.unionSet(6, 7);
  ds.unionSet(3, 8);
  ds.unionSet(8, 9);

  cout << ds.connected(1, 5) << endl;
  cout << ds.connected(5, 7) << endl;
  cout << ds.connected(4, 9) << endl;

  ds.unionSet(9, 4);
  cout << ds.connected(4, 9) << endl;
  cout << endl;
  ds.print();
  return 0;
}
