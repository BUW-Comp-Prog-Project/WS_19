#!usr/bin/env python3
"""Solution to SPOJ problem - Turbo Sort"""

def main():
	"""Sort any given list in ascending order."""
	l = []
	t = int(input())
	for i in range(t):
		l.append(int(input()))
	
	sorted_list = sorted(l) 

	for i in range(len(sorted_list)):
		print(sorted_list[i])

if __name__ == "__main__":
	main()
