import sys
def main():
    if len(sys.argv) != 2:
        exit(1)
    n = int(sys.argv[1])
    for i in range(n):
        if i == 1 or i == 0:
            continue
        for l in range(n-i):
            print(" ", end="")
        for j in range(i):
            print("#", end="")
        print("  ", end="")
        for k in range(i):
            print("#", end="")
        print()
    
    exit(0)

    
if __name__ == "__main__":
    main()
