class Searcher:
    iterationCount = 0                              # FOR COMPARISON


    def linearSearch(self,l:list,item,len):
        self.iterationCount = 0
        for i in range(len):
            self.iterationCount+=1

            if (l[i]==item):                        # COMPARE EVERY ELEMENT,SO O(N)
                return i
        return -1


    def sentinelSearch(self,l:list,item,len):
        self.iterationCount = 0
        last,l[len-1] = l[len-1],item
        i = 0
        while l[i]!=item:
            self.iterationCount+=1
            i+=1                                # ALTHOUGH T.C REMAINS O(N), IT IS GREATLY REDUCED
        
        l[len-1] = last
        return i


    def binarySearch(self,l:list,item,len):
        self.iterationCount = 0
        i,j = 0,len
        mid = int((i+j)/2)
        while(j>=i):
            self.iterationCount+=1
            
            if l[mid]==item: 
                return mid
            if l[mid]<item:
                i=mid+1
            if l[mid]>item:
                j=mid-1
            mid = int((i+j)/2)                      # SINCE 1/2 LIST IS DISCARDED EVERY TIME, O(LOG N)
        return -1
            
            
    def fibonacciSearch(self,l:list,item,len):
        self.iterationCount = 0
        fibo,k = [0,1,1],2

        while fibo[k]<len:
            k+=1
            fibo.append(fibo[k-1]+fibo[k-2])

        offset = -1

        while (fibo[k]>1):
            self.iterationCount+=1

            i = min(offset+fibo[k-2],len-1)

            if(l[i]<item):
                k-=1
                offset = i
            elif(l[i]>item):
                k-=2
            else: 
                return i

        if(fibo[k-1] and l[len-1] == item):
            return len-1                        # O(LOG N)
        return -1
                
                
s = Searcher()
ul = [9,5,7,4,2,6,1,8,11,63,27,17,99]
sl = [1,2,3,4,5,6,7,8,9,10,11,12,13]
length = 13
uTarget = 63
sTarget = 10
linearIndex = s.linearSearch(ul,uTarget,length)
linearIter =  s.iterationCount

sentinelIndex = s.sentinelSearch(ul,uTarget,length)
sentinelIter =  s.iterationCount

binaryIndex = s.binarySearch(sl,sTarget,length)
binaryIter =  s.iterationCount


fibonacciIndex = s.fibonacciSearch(sl,sTarget,length)
fibonacciIter =  s.iterationCount
print()
print("--------------------------------------------------------------------------------")
print(f"Unsorted list : {ul}\tTarget : {uTarget} ")
print("--------------------------------------------------------------------------------")
print(f"Linear search : \nElementIndex : {linearIndex}\t\tIterations : {linearIter}")
print(f"Sentinel search : \nElementIndex : {sentinelIndex}\t\tIterations : {sentinelIter}")
print("--------------------------------------------------------------------------------")
print(f"Sorted list : {sl}\tTarget : {sTarget} ")
print("--------------------------------------------------------------------------------")
print(f"Binary search : \nElementIndex : {binaryIndex}\t\tIterations : {binaryIter}")
print(f"Fibonacci search : \nElementIndex : {fibonacciIndex}\t\tIterations : {fibonacciIter}")
print("--------------------------------------------------------------------------------")
print()