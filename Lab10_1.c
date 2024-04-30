// 66070503421 Nutthawut Jaroenchokwittaya
// Floyd-Warshall
#include <stdio.h>



int min(int a, int b)
{
    return (a < b) ? a : b;              // use to find min of two value
}
void input(int size, int arr[size][size])
{
    int num;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf(" %d", &num);                // function use to input number
            if (num == -1)                      // if num is -1 then set it to infinity
            {
                arr[i][j] = 999;
                continue;
            }
            else
            {
                arr[i][j] = num;
            }
        }
    }
}
void floyd(int size, int arr[size][size])
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)            // floyd use to find shortest part
        {
            for (int j = 0; j < size; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

void printarr(int size,int arr[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j< size; j++){
            if( arr[i][j] == 999){
                printf("-1 ");                  // function use to print arr
                continue;
            }else{
                printf("%d ", arr[i][j]);
            }
        }
      printf("\n");
    }
}



int main()
{
    int size;
    scanf(" %d", &size);
    int arr[size][size];
    input(size, arr);
    floyd(size, arr);
    printarr(size,arr);

    return 0;
}