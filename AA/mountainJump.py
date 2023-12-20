def jump_energy(base_mountain: int, target_mountain: int) -> int:
    return abs(base_mountain - target_mountain)

def shortest_jump_path_energy(mountains) -> int:
    optimal_paths, cursor = [0], 1
    while cursor < len(mountains):
        pathway_energies: list[int] = [optimal_paths[cursor - 1] + jump_energy(mountains[cursor - 1], mountains[cursor])]
        if cursor > 1:
            pathway_energies.append(optimal_paths[cursor - 2] + jump_energy(mountains[cursor - 2], mountains[cursor]))

        optimal_paths.append(min(pathway_energies))
        cursor += 1
        print(pathway_energies)
        print(optimal_paths)
        print()
    return optimal_paths[-1]

# if __name__ == '_main_':
input()
mountains = [int(height) for height in input().split()]
print(mountains)
minimum_energy: int = shortest_jump_path_energy(mountains)
print(minimum_energy)