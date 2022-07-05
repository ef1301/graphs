class Disjoint:
    def __init__(self, size):
        self.roots = []
        for i in range(size):
            self.roots.append(i)
    def __str__(self):
        s = "["
        for i in range(len(self.roots)):
            if i == len(self.roots) - 1:
                s += str(self.roots[i])
            else:
                s += str(self.roots[i]) + ", "
        s += "]"
        return s
    def find(self, x):
        return self.roots[x]
    def unionSet(self,x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            for i in range(len(self.roots)):
                if self.roots[i] == rootY:
                    self.roots[i] = rootX
    def connected(self,x,y):
        return self.find(x) == self.find(y)


def main():
    ds = Disjoint(10)
    ds.unionSet(1, 2);
    ds.unionSet(2, 5);
    ds.unionSet(5, 6);
    ds.unionSet(6, 7);
    ds.unionSet(3, 8);
    ds.unionSet(8, 9);
    print(ds.connected(1, 5))
    print(ds.connected(5, 7))
    print(ds.connected(4, 9))

    print(ds)

if __name__ == "__main__":
    main()
