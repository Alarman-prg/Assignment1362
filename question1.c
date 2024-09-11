#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // initilize dynamic array of integers and information regarding array
    int arrSize = 0;
    int capacity = 0;
    int num = 0;

    int *arr = (int *)calloc(arrSize, sizeof(int));

    // test arr creation
    if(arr == NULL) {
        printf("Memory allocation unsucessful. Aborting.");
        return 1;
    }

    printf("Enter an integer and press enter, when all values are entered type done:\n");

    while(1) {
        if (scanf("%d", &num) != 1) {   // read int from cl and store in num var, then check if contents are an int.
            break;
        }

        //printf("\n%d", num);

        // check if there is space in arr for the new recieved int
        if (arrSize >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity + 1;  // if the arr is currently 0 resize to one else add one int sized space.
            int *newArr = (int *)realloc(arr, capacity * sizeof(int));

            //copy of allocation check
            if(newArr == NULL) {
                printf("Memory allocation unsucessful. Aborting.");
                free(arr);  //to prevent leak
                arr = NULL;
                return 1;
            }

            arr = newArr;   // save new arr       
        }

        arr[arrSize++] = num;

    }

    if (arrSize == 0) {
        printf("You didnt enter any values. Goodbye.\n");
        free(arr);  // to prevent leak
        arr = NULL;
        return 0;
    }
    

    printf("\nHere are the integers you entered but backwards!\n");
    for (int i = arrSize - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }    

    // freeing mem
    free(arr);
    arr = NULL;
    return 0;
}
