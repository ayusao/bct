def add(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)

    result = []
    carry = 0
    for i in range(n - 1, -1, -1):  # iterating in reverse order
        bita = int(a[i])
        bitb = int(b[i])
        sumbits = (bita + bitb + carry) % 2  # represented as 0 or 1
        carry = (bita + bitb + carry) // 2
        result.insert(0, str(sumbits))  # appends at the beginning
    result = ''.join(result)
    return result, carry


def negation(x):
    x = list(x)
    for i in range(len(x)):
        if x[i] == '1':
            x[i] = '0'
        else:
            x[i] = '1'
    return ''.join(x)


def sub(a, b):
    n = max(len(a), len(b))
    a = a.zfill(n)
    b = b.zfill(n)
    b = negation(b)
    b, carry = add(b, "1")  # 2's complement
    dif, _ = add(a, b)
    return dif


def leftshift(x, y):
    x = x[1:] + y[0]
    y = y[1:]
    return x, y


def div(dividend, divisor):
    q = dividend  # Initialize q with a default value
    m = divisor
    a = '0' * (len(q)+1)
    for i in range(len(dividend)):
        a, q = leftshift(a, q)
        a = sub(a, m)
        if a[0] == '1':
            q = q +'0' # Replace the last character with '0'
            a, _ = add(a, m) # Restoring
        else:
            q = q + '1'  # No need to restore
    return q, a

a = input("Enter dividend: ")
b = input("Divisor: ")
print("Quotient, Remainder:")
print(div(a, b))
