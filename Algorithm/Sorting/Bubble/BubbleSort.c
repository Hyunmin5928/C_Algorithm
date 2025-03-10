#include <stdio.h>

void BubbleSort(int Dataset[], int Length){
    int temp = 0;
    for(int i = 0; i < Length - 1; i++){
        for(int j = 0; j < Length - (i + 1); j++){
            if(Dataset[j] > Dataset[j + 1]){
                temp = Dataset[j + 1];
                Dataset[j + 1] = Dataset[j];
                Dataset[j] = temp;
            }
        }
    }
}

int main(void){
    int Dataset[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(Dataset)/sizeof(Dataset[0]);

    BubbleSort(Dataset, Length);

    for(int i = 0; i < Length; i++){
        printf("DataSet[%d] = %d\n", i, Dataset[i]);
    }
    printf("\n");

    return 0;
}