class myStr():
    s = ""
    def __init__(self,st):
        self.s = st

    def str_len(self,s):
        ctr = 0
        for _ in s:
            ctr += 1
        return ctr

    def count_words(self):
        word = ""
        words = []
        ctr = 0
        for ch in self.s+" ":
            if ch != " ":
                word+=ch
                ctr+=1
            else:
                words.append(word)
                word = ""
        max,op = 0,""
        for w in words:
            l = self.str_len(w)
            if (max<l):
                max = l
                op = w
        return op

    def char_count(self, c):
        ctr = 0
        for ch in self.s:
            if ch == c:
                ctr += 1
        return str(ctr)

    def check_palindrome(self):
        return self.s == self.s[::-1]

    def check_substring(self, substr):
        l1 = self.str_len(self.s)
        l2 = self.str_len(substr.s)

        for i in range(l1-l2+1):
            if self.s[i:i+l2] == substr.s:
                return str(i)
        return "NOT PRESENT"

    def word_freq(self):
        word = ""
        wordcount = {}
        for ch in self.s+" ":
            if ch != " ":
                word+=ch
            else:
                if word in wordcount:
                    wordcount[word]+=1
                else:
                    wordcount[word]=1
                word = ""
        op = ""
        for word in wordcount:
            op+= word + " : " + str(wordcount[word]) + "\n"
        return op

def menu():
    print("-------SELECT Question----------")
    print("1.To display word with the longest length")
    print("2.To determines the frequency of occurrence of particular character in the string")
    print("3.To check whether given string is palindrome or not")
    print("4.To display index of first appearance of the substring")
    print("5.To count the occurrences of each word in a given string")
    inp = int(input("Enter choice : "))
    obj = myStr(input("Enter string : "))
    if inp == 1:
        return "Longest word is "+ obj.count_words()
    elif inp == 2:
        ch = input("Enter char : ")
        return "The given character occurs " + obj.char_count(ch) + " times in the string."
    elif inp == 3:
        return "String is " + "palindrome." if obj.check_palindrome() else "not palindrome."
    elif inp == 4:
        ss = myStr(input("Enter substr : "))
        return "The substring is present at index location : " + obj.check_substring(ss)
    if inp == 5:
        return obj.word_freq()

print(menu())