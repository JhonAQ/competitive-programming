def solve():
    n = int(input())
    intervals = []
    for _ in range(n):
        a, b = map(int, input().split())
        intervals.append((a, b))

    for t1 in range(-100, 101):
        for t2 in range(t1, 101):
            valid = True
            for a, b in intervals:
                if not (
                    t1 <= a <= b <= t2
                    or t1 <= a <= b
                    or a <= t1 <= b <= t2
                    or a <= t1 <= b
                    or a <= b <= t2
                    or t1 <= a <= t2 <= b
                    or t1 <= a <= b <= t2
                ):
                    if not (
                        (a <= t1 <= b)
                        or (a <= t2 <= b)
                        or (t1 <= a <= b and t1 <= b <= t2)
                        or (t1 <= a <= t2 and t2 <= b)
                    ):
                        valid = False
                        break
            if valid:
                possible = True
                for a, b in intervals:
                    can_place = False
                    if (
                        (t1 <= a <= b and a <= t1 <= b)
                        or (t1 <= a and a <= t2 and t1 <= b and b <= t2)
                        or (a <= t1 and b >= t1 and a <= t1 and t1 <= b)
                    ):
                        can_place = True

                    if (
                        (t2 <= a <= b and a <= t2 <= b)
                        or (t2 <= a and a <= t2 and t2 <= b and b <= t2)
                        or (a <= t2 and b >= t2 and a <= t2 and t2 <= b)
                    ):
                        can_place = True

                    if not can_place:
                        possible = False
                        break

                if possible:
                    print(t1, t2)
                    return

    print("-1")


solve()
