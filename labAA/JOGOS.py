MOD = 10**7

def calculate_divisors(n, factors):
    numDivisors = 1
    sumDivisors = 1
    productDivisors = 1
    
    for i in range(n):
        a, k = factors[i]
        
        numDivisors = (numDivisors * (k + 1)) % MOD
        sumDivisors = (sumDivisors * ((pow(a, k+1, MOD) - 1) * pow(a-1, MOD-2, MOD))) % MOD
        productDivisors = (productDivisors * pow(a, k, MOD)) % MOD
    
    return numDivisors, sumDivisors, productDivisors

# Read input
n = int(input())
factors = []

for _ in range(n):
    a, k = map(int, input().split())
    factors.append((a, k))

# Calculate and print the divisors
numDivisors, sumDivisors, productDivisors = calculate_divisors(n, factors)
print(numDivisors, sumDivisors, productDivisors)
