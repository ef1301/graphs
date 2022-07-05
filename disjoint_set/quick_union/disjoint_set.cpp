#include <iostream>
#include <vector>

using namespace std;

class Disjoint {
  public:
  Disjoint(int size) : roots(size) {
    for (int i = 0; i < size; i++) {
      roots[i] = i;
    }
  }

  int find(int x) {
    while (x != roots[x]) {
      x = roots[x];
    }
    return x;
  }

  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      roots[rootY] = rootX;
    }
  }

  bool connected(int x, int y) {
    return find(x) == find(y);
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
  return 0;
}
