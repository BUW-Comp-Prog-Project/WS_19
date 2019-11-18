#!/usr/bin/env python3
"""Solution to SPOJ problem #24 - Small Factorials."""

N = 100


def compute_factorials():
    factorials = []
    f = 1
    for i in range(1, N + 1):
        f *= i
        factorials.append(f)
    return factorials


def main():
    """For any integer n, print n!"""
    factorials = compute_factorials()
    t = int(input())
    for i in range(t):
        N = int(input())
        print(factorials[N - 1])


if __name__ == "__main__":
    main()
