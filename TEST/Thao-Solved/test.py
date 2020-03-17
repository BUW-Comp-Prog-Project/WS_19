#!/usr/bin/env python3
"""Solution to SPOJ problem #1 - Life, the Universe, and Everything."""


def main():
    """
    Rewrite numbers from input to output, stop processing when reaching number
    42.
    """
    while True:
        entry = input()
        if entry == "42":
            break
        else:
            print(entry)


if __name__ == "__main__":
    main()
