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
    if carry:
        result.insert(0, str(carry))     
    return ''.join(result) 

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
    a = a.zfill(n)
    b = b.zfill(n)
    b = negation(b)
    print("neg.",b)
    b = add(b,"1") #2's comp
    print("2's comp",b)
    dif= add(a,b)
    carry = add(a,b)
    if (carry==0):
        return add(negation(dif),"1")
    else: 
        return dif[1:]


a=input("Enter the first number: ")
b=input("Enter the second number: ")

print(" Subtraction of 2nd from 1st: ")
print(sub(a,b))