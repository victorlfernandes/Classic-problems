import collections

def prime_factors(n):

    i = 2
    factors = list()

    while i ** 2 <= n:

        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
        
    if n > 1:
        factors.append(n)

    return factors

def main():

    while True:
         
        try:

            n, m = list(map(int, input().split()))

            factors = collections.Counter(prime_factors(m))

            divides = True
            for prime, freq in factors.items():
                
                t_freq = 0
                aux = prime

                while n >= aux:

                    t_freq += n // aux
                    aux = aux * prime
                
                if t_freq < freq:
                    divides = False
                    break

            if m == 0:
                divides = False

            if not divides:
                print('{} does not divide {}!'.format(m, n))
            else:
                print('{} divides {}!'.format(m, n))

        except(EOFError):
            break

if __name__ == '__main__':
    main()