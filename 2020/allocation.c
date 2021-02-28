/*
N^2 complexity is not great
This doesn't pass the second case because there's 10^5 cases
Maybe I'll try in python
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_PRICE 1001

void nextHouse(int *houses, int *price, int *house, int N, int boughtHouses) {
    // find next house after the last one bought
    int lowestPrice = MAX_PRICE;
    int lowestHouse = -1;
    for (int k = 0; k < N - boughtHouses; k++) {
        if (houses[k] < MAX_PRICE) {
            if (houses[k] < lowestPrice) {
                lowestPrice = houses[k];
                lowestHouse = k;
            }
        }
    }
    (*price) = lowestPrice;
    (*house) = lowestHouse;
}

int ensurePurchase(int price, int *balance, int *total, int *houses, int k, int N) {
    if (((*balance) - price) >= 0) {
        (*balance) -= price;
        (*total)++;

        // Put bought house at the end of the list
        houses[k] = houses[N-(*total)];
        houses[N-(*total)] = MAX_PRICE;
        return 1;
    } else return 0;
}

int main() {
    int T, N, balance;
    scanf("%d", &T);
    getchar();
    for(int caseNumber = 1; caseNumber <= T; caseNumber++) {
        // Read number of houses and balance
        scanf("%d %d", &N, &balance);
        getchar();

        // Read house prices
        int houses[N], price, total = 0;
        for (int k = 0; k < N; k++)
            scanf("%d", &(houses[k]));
        
        price = -1;
        int house = -1;
        nextHouse(houses, &price, &house, N, total);
        while (total < N && ensurePurchase(price, &balance, &total, houses, house, N)) {
            nextHouse(houses, &price, &house, N, total);
        }
        printf("Case #%d: %d\n", caseNumber, total);
    }
    return 0;
}