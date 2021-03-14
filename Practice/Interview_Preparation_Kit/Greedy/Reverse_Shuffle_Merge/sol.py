def reverseShuffleMerge(s):
    from collections import defaultdict
    count_dict = defaultdict(int)
    used_dict = defaultdict(int)
    result = []
    for c in s:
        count_dict[c] += 1
    
    remain_dict = dict(count_dict)

    for c in reversed(s):
        if (count_dict[c] // 2) > used_dict[c]:
            while result and result[-1] > c and (used_dict[result[-1]] + remain_dict[result[-1]]) > (count_dict[result[-1]] // 2):
                pop_char = result.pop()
                used_dict[pop_char] -= 1
            used_dict[c] += 1
            result.append(c)
        remain_dict[c] -= 1
    return "".join(result)