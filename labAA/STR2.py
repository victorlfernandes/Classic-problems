def count_distinct_substrings(string):
    n = len(string)
    suffix_array = sorted(range(n), key=lambda i: string[i:])
    
    lcp_array = [0] * n
    for i in range(1, n):
        x, y = suffix_array[i-1], suffix_array[i]
        while x < n and y < n and string[x] == string[y]:
            lcp_array[i] += 1
            x += 1
            y += 1
    
    distinct_substrings = [0] * n
    for i in range(1, n):
        distinct_substrings[suffix_array[i]] = n - suffix_array[i]
    
    for i in range(1, n):
        distinct_substrings[i] -= lcp_array[i]
    
    for count in distinct_substrings[1:]:
        print(count, end=" ")
    print(0)  # Last substring of length n has 0 distinct substrings

# Example usage
string = "mississippi"
count_distinct_substrings(string)
