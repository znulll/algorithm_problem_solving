import sys

def main():
    a = list(map(int, sys.stdin.readline().split()))
    A = a[0]
    B = a[1]
    C = a[2]

    ## line1: (A+B)%C
    print((A+B)%C)

    ## line2: ((A%C) + (B%C))%C
    print(((A%C) + (B%C))%C)

    ## line3: (A×B)%C
    print((A*B)%C)

    ## line4: ((A%C) × (B%C))%C
    print(((A%C) * (B%C))%C)


if __name__ == "__main__":
    main()