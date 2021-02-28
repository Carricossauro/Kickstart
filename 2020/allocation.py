'''
Passed all tests easily
This is why I hate C, first try did it
'''

def main():
    T = int(input())
    for case in range(1,T+1):
        [N, balance] = map(int, input().split())
        prices = list(map(int, input().split()))
        prices.sort()
        total = 0
        for housePrice in prices:
            if (balance - housePrice) < 0:
                break
            else:
                balance -= housePrice
                total+=1
        print("Case #{}: {}".format(case, total))

main()