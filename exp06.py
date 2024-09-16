class Sorter():
    recursionCount = 0
    swapCount = 0
    def __init__(self,l:list):
        self.l=l
    
    def swap(self,i,j):
        self.swapCount+=1
        self.l[i],self.l[j] = self.l[j],self.l[i]

    def arrangePivot(self,lb,ub):
        pivot = self.l[lb]
        i,j = lb,ub

        while(i<j):
            while self.l[i]<=pivot: i+=1
            while self.l[j]>pivot : j-=1
            if (i<j): self.swap(i,j)
        self.swap(lb,j)

        return j

    def quickSort(self,lb,ub):
        if(lb<ub):
            self.recursionCount+=1
            j = self.arrangePivot(lb,ub)
            self.quickSort(lb,j)
            self.quickSort(j+1,ub)

l = [90.0,99.7,96.3,98.7,12.3,34.5,45.6,67.8,78.9,89.0]
ln = 10

s = Sorter(l)
s.quickSort(0,ln-1)

quickRecrCnt =  s.recursionCount
quickSwapCnt = s.swapCount

print()
print("--------------------------------------------------------------------------------")
print(f"Unsorted list : {l}")
print("--------------------------------------------------------------------------------")
print(f"Quick Sort: \nSwaps : {quickSwapCnt}\t\tRecursions : {quickRecrCnt}")
print("--------------------------------------------------------------------------------")
print(f"Top 5 According to Quick Sort : {s.l[:ln-6:-1]}")
print("--------------------------------------------------------------------------------")
print()