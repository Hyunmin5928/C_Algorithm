#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int len){
    int temp;
    for(int i = 1; i < len; i++){
        if(DataSet[i - 1] <= DataSet[i])
            continue;
        
        temp = DataSet[i];
        for(int j = 0; j < i; j++){
            if(DataSet[j] > temp){
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                DataSet[j] = temp;
                break;
            }
        }
    }
}

int main(void){
    int DataSet[] = {1, 6, 5, 4, 2, 3};
    int len = sizeof(DataSet) / sizeof(DataSet[0]);

    InsertionSort(DataSet, len);
    
    for(int i = 0; i < len; i++){
        printf("Data[%d] = %d\n", i, DataSet[i]);
    }

    return 0;
}