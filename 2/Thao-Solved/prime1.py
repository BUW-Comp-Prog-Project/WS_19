#!/usr/bin/env python3
"""Solution to SPOJ problem #2 - Prime Generator."""

import math


def all_primes(upper_bound):
    prime_list = []
    is_prime = [True for i in range(upper_bound + 1)]
    for i in range(2, upper_bound + 1):
        if is_prime[i]:
            prime_list.append(i)
            for j in range(i * i, upper_bound + 1, i):
                is_prime[j] = False
    return prime_list


def segmented_sieve(lower_bound, upper_bound):
    delta = int(math.sqrt(upper_bound)) + 1
    count = upper_bound - lower_bound + 1
    is_prime = [True for i in range(count + 1)]
    prime_list = all_primes(delta)
    primes = []
    for i in range(len(prime_list)):
        limit = int(lower_bound / prime_list[i]) * prime_list[i]
        if limit < lower_bound:
            limit += prime_list[i]
        if limit == prime_list[i]:
            limit += prime_list[i]
        for j in range(limit, upper_bound + 1, prime_list[i]):
            is_prime[j - lower_bound] = False
    for i in range(lower_bound, upper_bound + 1):
        if is_prime[i - lower_bound]:
            primes.append(i)
    return primes


def main():
    """Print all prime numbers within a given range."""
    t = int(input())  # number of test cases
    for i in range(t):
        m, n = input().split()
        m = int(m)
        n = int(n)
        if m < 2:
            m = 2
        prime_list = segmented_sieve(m, n)
        for j in prime_list:
            print(j)


if __name__ == "__main__":
    main()
