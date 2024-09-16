Studs = [1,2,3,4,5,6,7,8,9]
playC = [1,2,3,4,5]
playB = [3,4,5,6,7]
playF = [2,3,7,8,9]

def setIntersect(A:list,B:list):
    sol = []
    for a in A:
        if (a in B):
            sol.append(a)
    return sol

def setUnion(A:list,B:list):
    sol = []
    for a in A:
        sol.append(a)
    for b in B:
        if b not in sol:
            sol.append(b)
    return sol

def setDifference(A:list,B:list):
    sol = []
    for a in A:
        if a not in B:
            sol.append(a)
    return sol

def Menu(i):
    if i == 1:
        return setIntersect(playC, playB)

    playCB = setUnion(playC, playB)
    if i == 2:
        playOnlyCB = setIntersect(playC, playB)
        return setDifference(playCB, playOnlyCB)
    if i == 3:
        return countElements(setDifference(Studs, playCB))
    if i == 4:
        playCBF = setIntersect(playCB, playF)
        return countElements(setDifference(playCBF, playB))

def takeInput(disp:str):
    inp = input("Enter students who " + disp + " separated by space : ")
    return inp.split(sep=" ")

def countElements(l:list):
    ctr = 0
    for e in l:
        ctr+=1
    return ctr

#Studs = takeInput("are CE students")
#playC = takeInput("play cricket")
#playB = takeInput("play badminton")
#playF = takeInput("play football")

print("-------SELECT Question----------")
print("1.List of students who play both cricket and badminton")
print("2.List of students who play either cricket or badminton but not both")
print("3.Number of students who play neither cricket nor badminton")
print("4.Number of students who play cricket and football but not badminton.")
print(Menu(int(input())))