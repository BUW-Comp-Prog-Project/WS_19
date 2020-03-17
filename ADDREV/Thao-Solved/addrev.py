#!/usr/bin/env python3
"""Solution to SPOJ problem #42 - Adding Reversed Numbers."""


def reverse_number(input_number):
    """Reverse a positive integer."""
    return int(str(input_number)[::-1])


def main():
    """Add two reversed numbers and display the reversed sum."""
    n = int(input())
    for i in range(n):
        a, b = input().split()
        reversed_a = reverse_number(a)
        reversed_b = reverse_number(b)
        reversed_sum = reverse_number(reversed_a + reversed_b)
        print(reversed_sum)


if __name__ == "__main__":
    main()
