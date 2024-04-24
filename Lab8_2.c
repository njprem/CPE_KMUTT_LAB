//66070503421 Nutthawut
// Maxheap using arrray

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct tree
{                                        //decalre struct
    int *maxheap;
    int max;
    int size;
} heap;




heap *createheap(int full)
{
    heap *ptr = (heap *)malloc(sizeof(heap));
    ptr->maxheap = (int *)malloc(full * sizeof(int));
    ptr->max = full;
    ptr->size = 0;                                      // creat heap
    return ptr;
}




void swap(int *a, int *b){
    int temp = *b;                                     // function to swap tree
    *b = *a;
    *a = temp;
}




void heapify(heap *root, int i){
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < root->size && root-> maxheap[l] > root->maxheap[largest])    
      largest = l;
  if(r < root->size && root->maxheap[r] > root->maxheap[largest])
      largest = r;
                              // parent is greater than child
  if(largest != i){
      swap(&root->maxheap[i], &root->maxheap[largest]);
      heapify(root, largest);
  }
}





int extractmax(heap *root){
    if(root->size <= 0){
        return -1;              //extract root(because it largest) palce in lease element
    }                            // and decrease size
 int max = root->maxheap[0];

    root->maxheap[0] = root->maxheap[root->size - 1];
    root->size--;
    heapify(root, 0);
    return max;
}





void insert(heap *root, int value){
    if(root->size == root->max){
        return;
    }

  int i = root->size++;
  root->maxheap[i] = value;

  while(i != 0 && root->maxheap[(i - 1) / 2] < root->maxheap[i]){
      swap(&root->maxheap[i], &root->maxheap[(i - 1) / 2]);
      i = (i - 1) / 2;
  }
}



void deleted(heap *root, int value){
    if(root->maxheap == 0){
        return;
    }

    int i = 0;
    while(root->maxheap[i] != value){
        i++;
    }
    swap(&root->maxheap[i], &root->maxheap[root->size - 1]);
    root->size--;

    for(int i = (root->size / 2) - 1; i >= 0; i--){
        heapify(root, i);
    }
}




void print(heap *root){
    for(int i = 0; i < root->size; i++){
        printf("%d ", root->maxheap[i]);
    }
    printf("\n");
}
int main()
{
    heap *root = createheap(99);
    char *choices = (char *)malloc(10 * sizeof(char));
    if (choices == NULL) {
        free(root->maxheap);                
        free(root);
        return 0 ;
    }
    int temp;
    while (1)
    {
        scanf(" %s", choices);
        if (strcmp(choices, "INSERT") == 0)
        {
            while (scanf(" %d", &temp) == 1)
            {
                insert(root, temp);
            }
        }
        else if (strcmp(choices, "DELETE") == 0)
        {
            while (scanf(" %d", &temp) == 1)
            {
                deleted(root, temp);
            }
        }
        else if(strcmp(choices, "PRINT") == 0){
            print(root);
        }
        else if(strcmp(choices, "EXIT") == 0){
            break;
        }
    }
  free(root->maxheap);
  free(root);
  free(choices);
  return 0;
}
