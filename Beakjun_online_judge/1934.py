import sys

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def lcm(a, b, g):
    return (int) (a*b/g)

def main():
    testcase = int(sys.stdin.readline())

    for i in range(0, testcase):
        input = list(map(int, sys.stdin.readline().split()))
        
        a = input[0]
        b = input[1]

        g = gcd(a, b)
        l = lcm(a, b, g)
        print(l)

if __name__ == "__main__":
    main()