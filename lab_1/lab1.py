import time

m = 2048
n = 3072

def cfGCD(m, n):
    counter = 0
    gcd = 1
    for i in range(1, min(m, n) + 1):
        counter += 1
        if m % i == 0:
            counter += 1
            if n % i == 0:
                gcd = i
    print(f"Number of divisions: {counter}")
    return gcd

def egcd(m, n):
    counter = 0
    while n != 0:
        r = n
        n = m % r
        counter += 1
        m = r
    print(f"Number of divisions: {counter}")
    return m


start = time.perf_counter()
print(cfGCD(m, n))
end = time.perf_counter()
print(f"time taken for common factors method: {end - start} seconds")
start = time.perf_counter()
print(egcd(m, n))
end = time.perf_counter()
print(f"time taken for common factors method: {end - start} seconds")





