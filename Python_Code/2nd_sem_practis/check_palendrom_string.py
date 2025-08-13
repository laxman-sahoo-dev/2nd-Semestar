def check_palen_str(str):
    lower_str=""
    for ch in str:
        if 'A'<=ch<='Z':
            lower_str+=chr(ord(ch)+32)
        else:
            lower_str+=ch
    
    clean_str="" 
    for ch in lower_str:
        if ('A'<=ch<='z') or ('a'<=ch<='z'):
            clean_str+=ch
    left=0
    right=len(clean_str)-1
    while(left<right):
        if clean_str[left]!=clean_str[right]:
            return False
        left+=1
        right-=1
    return True
str=input("Enter string for checking palendrom-")
if (check_palen_str(str)):
    print("It is pallendrom")
else:
    print("It is not palendrom")