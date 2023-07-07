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
        carry =  (bita + bitb + carry)// 2
        #print(carry,"\t", sumbits)
        result.insert(0, str(sumbits)) #appends at the first
    #end of for loop 
    if carry:
        result.insert(0, str(carry))
    return ''.join(result)       

a=input("Enter the first number: ")
b=input("Enter the second number: ")

print("Addition: ")
print(add(a,b))