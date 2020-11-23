import sys

def main():
    E, S, M = map(int,input().split())
    e, s, m, year = 0, 0, 0, 0
    mod_e = 16
    mod_s = 29
    mod_m = 20

    while True:
        if e == E and s == S and m == M:
            break
        e += 1
        s += 1
        m += 1
        year += 1
        if e == mod_e: 
            e = 1
        if s == mod_s:
            s = 1
        if m == mod_m: 
            m = 1
    
    print(year)

if __name__ == "__main__":
    main()
