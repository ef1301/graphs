class Disjoint:
    def __init__(self, size):
        self.roots = [i for i in range(size)]
    def find(self, x):
        while x != self.roots[x]:
            x = self.roots[x]
        return x
    def unionSet(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.roots[rootY] = rootX
    def connected(self, x, y):
        return self.find(x) == self.find(y)

def main():
    ds = Disjoint(10);
    ds.unionSet(1, 2);
    ds.unionSet(2, 5);
    ds.unionSet(5, 6);
    ds.unionSet(6, 7);
    ds.unionSet(3, 8);
    ds.unionSet(8, 9);

    print(ds.connected(1, 5))
    print(ds.connected(5, 7))
    print(ds.connected(4, 9))

    ds.unionSet(9, 4);

    print(ds.connected(4, 9))
    return
if __name__ == "__main__":
    main()
