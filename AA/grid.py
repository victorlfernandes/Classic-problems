def solve(H, W, grid, dp):
    mod = 10 ** 9 + 7
    for i in range(H):
        for j in range(W):
            if i < H - 1:
                if grid[i + 1][j] == '.':
                    dp[i + 1][j] += dp[i][j] % mod
            if j < W - 1:
                if grid[i][j + 1] == '.':
                    dp[i][j + 1] += dp[i][j] % mod
    return(dp[H - 1][W - 1] % mod)

def main():
    H, W = map(int, input().split())
    grid = [str(input()) for _ in range(H)]
    dp = [[0] * W for _ in range(H)]
    dp[0][0] = 1
    print(solve(H, W, grid, dp))

if __name__ == '__main__':
    main()