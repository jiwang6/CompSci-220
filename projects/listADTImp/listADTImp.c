#include "listADT.h"

int main() {
    //printf("ah ____, here we go again\n");

    list userNums = createList();

    for (int i = 0; i < 6; i++) // 0 1 2 3 4 5
        append(&userNums, i);
    for(int i = 0; i < userNums.size; i++) // check array vals
        printf("%d", userNums.items[i]);

    printf("\n%d", binarySearch(userNums, 30));



    //insertAfter(&userNums, 2, 8);
    /* 
    // testing/reviewing pointers because I have the memory of a turnip

    list* testStruct = &userNums;

    testStruct->items[0] = 45;

    printf("%d\n", testStruct->items[0]);
    // is the same as
    printf("%d\n", (*testStruct).items[0]);
    */

    return 0;
}