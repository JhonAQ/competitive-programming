def solve_laundry_problem(test_cases):
    results = []
    for k, counts in test_cases:
        c1, c2, c3, c4, c5, c6, c7 = counts
        # Initialize
        total_items_A = c1
        total_items_B = c2
        total_items_C = c3
        lA = (total_items_A + k - 1) // k
        lB = (total_items_B + k - 1) // k
        lC = (total_items_C + k - 1) // k
        rA = lA * k - total_items_A
        rB = lB * k - total_items_B
        rC = lC * k - total_items_C

        # Process c4 (A and B)
        c4_items = c4
        while c4_items > 0 and (rA > 0 or rB > 0):
            if rA >= rB:
                m = min(c4_items, rA)
                total_items_A += m
                rA -= m
            else:
                m = min(c4_items, rB)
                total_items_B += m
                rB -= m
            c4_items -= m

        if c4_items > 0:
            delta_lA = ((total_items_A + c4_items + k - 1) // k) - lA
            delta_lB = ((total_items_B + c4_items + k - 1) // k) - lB
            if delta_lA <= delta_lB:
                total_items_A += c4_items
                lA += delta_lA
            else:
                total_items_B += c4_items
                lB += delta_lB

        # Process c5 (B and C)
        c5_items = c5
        while c5_items > 0 and (rB > 0 or rC > 0):
            if rB >= rC:
                m = min(c5_items, rB)
                total_items_B += m
                rB -= m
            else:
                m = min(c5_items, rC)
                total_items_C += m
                rC -= m
            c5_items -= m

        if c5_items > 0:
            delta_lB = ((total_items_B + c5_items + k - 1) // k) - lB
            delta_lC = ((total_items_C + c5_items + k - 1) // k) - lC
            if delta_lB <= delta_lC:
                total_items_B += c5_items
                lB += delta_lB
            else:
                total_items_C += c5_items
                lC += delta_lC

        # Process c6 (A and C)
        c6_items = c6
        while c6_items > 0 and (rA > 0 or rC > 0):
            if rA >= rC:
                m = min(c6_items, rA)
                total_items_A += m
                rA -= m
            else:
                m = min(c6_items, rC)
                total_items_C += m
                rC -= m
            c6_items -= m

        if c6_items > 0:
            delta_lA = ((total_items_A + c6_items + k - 1) // k) - lA
            delta_lC = ((total_items_C + c6_items + k - 1) // k) - lC
            if delta_lA <= delta_lC:
                total_items_A += c6_items
                lA += delta_lA
            else:
                total_items_C += c6_items
                lC += delta_lC

        # Process c7 (A, B, C)
        c7_items = c7
        while c7_items > 0 and (rA > 0 or rB > 0 or rC > 0):
            max_r = max(rA, rB, rC)
            if max_r == rA:
                m = min(c7_items, rA)
                total_items_A += m
                rA -= m
            elif max_r == rB:
                m = min(c7_items, rB)
                total_items_B += m
                rB -= m
            else:
                m = min(c7_items, rC)
                total_items_C += m
                rC -= m
            c7_items -= m

        if c7_items > 0:
            delta_lA = ((total_items_A + c7_items + k - 1) // k) - lA
            delta_lB = ((total_items_B + c7_items + k - 1) // k) - lB
            delta_lC = ((total_items_C + c7_items + k - 1) // k) - lC
            min_delta = min(delta_lA, delta_lB, delta_lC)
            if min_delta == delta_lA:
                total_items_A += c7_items
                lA += delta_lA
            elif min_delta == delta_lB:
                total_items_B += c7_items
                lB += delta_lB
            else:
                total_items_C += c7_items
                lC += delta_lC

        # Recalculate loads
        lA = (total_items_A + k - 1) // k
        lB = (total_items_B + k - 1) // k
        lC = (total_items_C + k - 1) // k

        total_loads = lA + lB + lC
        results.append(total_loads)
    return results


# Read input
t = int(input())
test_cases = []
for _ in range(t):
    k = int(input())
    counts = list(map(int, input().split()))
    test_cases.append((k, counts))

# Solve problem
results = solve_laundry_problem(test_cases)

# Output results
for res in results:
    print(res)
