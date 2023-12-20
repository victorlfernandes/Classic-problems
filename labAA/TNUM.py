import math

MOD = int(1e9) + 7

def calculateDivisors(num):
    divisors = []
    
    i = 1
    while i * i <= num:
        if num % i == 0:
            divisors.append(i)
            if num // i != i:
                divisors.append(num // i)
        i += 1
    
    divisors.sort()
    return divisors

def calculate_divisors(n, factors):
    num_divisors = 1
    sum_divisors = 1
    product_divisors = 1

    number = 1
    
    for factor, power in factors:
        # Calculate the number of divisors
        num_divisors = (num_divisors * (power + 1)) % MOD
        
        # Calculate the sum of divisors
        sum_factor = (pow(factor, power + 1, MOD) - 1) * pow(factor - 1, MOD - 2, MOD)
        sum_divisors = (sum_divisors * sum_factor) % MOD
        
        # Calculate the product of divisors
        # product_factor = pow(factor, power * (power + 1) // 2, MOD)
        # product_divisors = (product_divisors * product_factor) % MOD
        # print(product_factor)
        # print(product_divisors)
        number *= pow(factor, power)
    
    divisors = calculateDivisors(number)
    s = 1
    for i in divisors:
        s = (s * i) % MOD
    
    # return num_divisors, sum_divisors, product_divisors
    return num_divisors, sum_divisors, s

# Read the input
n = int(input())
factors = []
for _ in range(n):
    factor, power = map(int, input().split())
    factors.append((factor, power))

# Calculate the divisors
num_divisors, sum_divisors, product_divisors = calculate_divisors(n, factors)

# Print the output
print(num_divisors, sum_divisors, product_divisors)
