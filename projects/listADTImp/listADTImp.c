#include "listADT.h"

int main() {
    printf("ah //merde//, here we go again\n");

    list userNums = createList();

    if (!append(&userNums, 8))
        printf("error in append \n");

    printf("%d\n", userNums.items[0]);

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