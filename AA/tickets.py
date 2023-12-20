def calculate_best_price(days, costs) -> int:
    total_analysed_days: int = (days[-1] + 1)
    best_values_per_day = [0] * total_analysed_days
    for day in range(1, total_analysed_days):        
        if day in days:
            best_values_per_day[day] = min(
                best_values_per_day[max(day - 30, 0)] + costs[2],
                best_values_per_day[max(day - 7, 0)] + costs[1],
                best_values_per_day[max(day - 1, 0)] + costs[0]
            )
            print(best_values_per_day[day])
        else: best_values_per_day[day] = best_values_per_day[day - 1]
    print(best_values_per_day)
    return best_values_per_day[-1]

# if _name_ == '_main_':
input()
prices = [int(price) for price in input().split()]
target_days = [int(day) for day in input().split()]

best_price: int = calculate_best_price(target_days, prices)
print(best_price, end='')