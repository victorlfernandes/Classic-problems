def solve(n, grid, dp):
    mod = 10 ** 9 + 7
    for i in range(n):
        for j in range(n):
            if i < n - 1:
                if grid[i + 1][j] == '.':
                    dp[i + 1][j] += dp[i][j] % mod
            if j < n - 1:
                if grid[i][j + 1] == '.':
                    dp[i][j + 1] += dp[i][j] % mod
    return(dp[n - 1][n - 1] % mod)

def main():
    n = int(input())
    grid = [str(input()) for _ in range(n)]
    dp = [[0] * n for _ in range(n)]
    dp[0][0] = 1
    print(solve(n, grid, dp))

if __name__ == '__main__':
    main()