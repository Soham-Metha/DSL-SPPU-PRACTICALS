class Searcher:
    def insertionSort(self,l:list,len,gap=1):
        for i in range(gap,len,gap):
            self.iterationCount+=1

            for j in range(i-gap,-1,-gap):
                if l[j+gap]<l[j]: self.swap(l,j,j+gap)
                else : break
                
            '''SAME WITH WHILE LOOP
            j = i-gap
            while j>=0 and l[j+gap]>l[j]:
                swap(l,j,j+gap)
                j-=gap
            '''

    def shellSort(self,l:list,len):
        gap = len//2
        while gap>0:
            self.passCount+=1
            self.insertionSort(l,len,gap)
            gap = gap//2
        
    def rst(self):
        self.iterationCount = 0
        self.swapCount = 0
        self.passCount = 0

    def swap(self,l,i,j):
        self.swapCount+=1
        l[i],l[j] = l[j],l[i]

s = Searcher()
l = [90.0,99.7,96.3,98.7,12.3,34.5,45.6,67.8,78.9,89.0]
insertionSortL = [i for i in l]
shellSortL = [i for i in l]
ln = 10

s.rst()
s.insertionSort(insertionSortL,ln)
insertionIterCnt =  s.iterationCount
insertionSwapCnt = s.swapCount

s.rst()
s.shellSort(shellSortL,ln)
shellPassCnt =  s.passCount
shellIterCnt =  s.iterationCount
shellSwapCnt = s.swapCount

print()
print("--------------------------------------------------------------------------------")
print(f"Unsorted list : {l}")
print("--------------------------------------------------------------------------------")
print(f"Insertion Sort: \nSwaps : {insertionSwapCnt}\t\tIterations : {insertionIterCnt}")
print(f"Shell Sort : \nSwaps : {shellSwapCnt}\t\tIterations : {shellIterCnt}\t\tPasses : {shellPassCnt}")
print("--------------------------------------------------------------------------------")
print(f"Top 5 According to Insertion Sort : {insertionSortL[:ln-6:-1]}")
print(f"Top 5 According to Shell Sort : {shellSortL[:ln-6:-1]}")
print("--------------------------------------------------------------------------------")
print()
