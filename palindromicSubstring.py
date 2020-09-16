def checkPalindrome(string,start,end,memory):
    if(memory[start][end]==1):
        print("true")
        return True
    if(memory[start][end]==0):
        print("false")
        return False
    s=start
    e=end
    while(start<end):
       if(string[start]!=string[end]):
           memory[s][e]=0
           return False
       start+=1
       end-=1
    memory[s][e]=1
    return True

def threePalindromicSubstrings(word):
    length=len(word)
    memory = [[-1]*length for _ in range(length)]
    for i in range(length-2):
        if(checkPalindrome(word,0,i,memory)):
            for j in range(i+1,length-1):
                if checkPalindrome(word,i+1,j,memory) and checkPalindrome(word,j+1,length-1,memory):
                    return [word[:i+1],word[i+1:j+1],word[j+1:length]]
 #   print(memory)
    return ["Impossible"]
print(threePalindromicSubstrings("aaqqqqasdfeaaa"))
#print(threePalindromicSubstrings("aavaaaaaaalakjflkasjflasjdflkasjdflkasjdflkajdflkajdflkasjd;f"))
