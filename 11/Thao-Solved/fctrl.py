#!/usr/bin/env python3
"""Solution to SPOJ problem #11 - Factorial."""

import math


def count_zeros(n):
    zeros = 0
    i = 1
    while math.pow(5, i) <= n:
        zeros += math.floor(n / (math.pow(5, i)))
        i += 1
    return int(zeros)


def main():
    """
    For any positive integer n, count the number of trailing zeros at the end
    of n!.
    """
    t = int(input())
    for i in range(t):
        n = int(input())
        print(count_zeros(n))


if __name__ == "__main__":
    main()
