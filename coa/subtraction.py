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
        result.insert(0, str(sumbits)) #appends at the first
    #end of for loop 
    result = ''.join(result) 
    return result, carry

def negation(x):
    x = list(x)
    for i in range(0, len(x)):
        if (x[i] == '1'):
            x[i] = '0'
        else:
            x[i] = '1'
    return ''.join(x)

def sub(a,b):
    n = max(len(a), len(b))
    a = a.zfill(2*n+1)
    b = b.zfill(2*n+1)
    b = negation(b)
    #print("neg.",b)
    b, carry = add(b,"1") #2's comp
    #print("2's comp",b)
    dif, carry= add(a,b)
    #print("Sum ",dif)
    if (carry==1):
        return dif[1:]
        
    else: 
        dif, carry = add(negation(dif), "1") #2's comp
        if carry:
            dif.insert(0, str(carry))
        return ''.join(dif) 


a=input("Enter the first number: ")
b=input("Enter the second number: ")

print("Subtraction of 2nd from 1st: ")
print(sub(a,b))