class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        l=list(s)
        countf=0
        counts=0
        vowels= ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        mid=len(l)//2
        for i in range(0,mid):
            if l[i] in vowels:
                countf +=1
             
        for i in range (mid, len(l)):
            if l[i] in vowels:
                counts +=1
            
        if countf==counts:
            return True
        else :
            return False