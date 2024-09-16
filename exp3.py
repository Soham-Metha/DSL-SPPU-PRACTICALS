len = int(input("Enter no. : "))
def convertTo2D(l:list):
    l = [int(x) for x in l]
    return [l[tr*len:(tr+1)*len] for tr in range(len)]
class matrix:
    m = []
    n = []
    temp = []
    def __init__(self):
        self.temp = [[0] * len] * len
        m = input("Enter elements of 1st matrix : ").split(" ")
        n = input("Enter elements of 2nd matrix : ").split(" ")
        self.m = convertTo2D(m)
        self.n = convertTo2D(n)

    def add(self):
        for i in range(len):
            for j in range(len):
                self.m[i][j]+=int(self.n[i][j])

    def sub(self):
        for i in range(len):
            for j in range(len):
                self.m[i][j]-=int(self.n[i][j])

    def transpose(self):
        temp = [[0] * len] * len
        for i in range(len):
            for j in range(len):
                temp[i][j]=self.n[j][i]
        self.n = temp

    def mul(self):
        for i in range(len):
            for j in range(len):
                for k in range(len):
                    self.temp[i][j]+= self.m[i][k]*self.n[k][j]
        self.m = self.temp

    def show(self,m):
        for i in m:
            for j in i:
                print(j,end="\t")
            print()

m = matrix()

m.add()
m.show(m.m)
print()

m.sub()
m.show(m.m)
print()

m.mul()
m.show(m.m)
print()

m.transpose()
m.show(m.n)
print()
