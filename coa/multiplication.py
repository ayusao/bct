def add(a,b):
    #finding out the max length and ensuring both have same no of bits
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)
    
    result = []
    carry =0
    for i in range(len(a)-1, -1, -1): #iterating in reverse order
        bita = int(a[i])
        bitb = int(b[i])
        sumbits = (bita + bitb + carry)%2 #only represented in 0 or 1
        carry =  (bita + bitb + carry)//2
        result.insert(0, str(sumbits)) #appends at the first
    #end of for loop 
    result = ''.join(result) 
    return result, carry

def mul(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)
    tempa=''.zfill(n)
    for i in range(n-1, -1, -1):
        if (b[i] == "1"):
            tempa, crry = add(tempa, a)
            if (crry==1):
                tempa = str(crry) + tempa
        a = a + "0"
    return tempa
            
a=input("Enter the first number: ")
b=input("Enter the second number: ")

print("Multiplication: ")
print(mul(a,b))