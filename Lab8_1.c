//66070503421 Nutthawut
// Minheap using arrray

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct tree
{                                        //decalre struct
    int *minheap;
    int max;
    int size;
} heap;




heap *createheap(int full)
{
    heap *ptr = (heap *)malloc(sizeof(heap));
    ptr->minheap = (int *)malloc(full * sizeof(int));
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
  int smallest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if(l < root->size && root->minheap[l] < root->minheap[smallest])
      smallest = l;                                                    
  if(r < root->size && root->minheap[r] < root->minheap[smallest])
      smallest = r;                              // parent node has to be less than child node

  if(smallest != i){
      swap(&root->minheap[l], &root->minheap[smallest]);
      heapify(root, smallest);
  }
}





int extractmin(heap *root){
    if(root->size <= 0){
        return -1;              //extract root(because it smallest) palce in lease element
    }                            
    int min = root->minheap[0];

    root->minheap[0] = root->minheap[root->size - 1];
    root->size--;
    heapify(root, 0);
    return min;
}





void insert(heap *root, int value){
    if(root->size == root->max){
        return;
    }

    int i = root->size++;
    root->minheap[i] = value;                            

    while(i != 0 && root->minheap[(i - 1) / 2] > root->minheap[i]){
        swap(&root->minheap[i], &root->minheap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}



void deleted(heap *root, int value){
    if(root->minheap == NULL || root->size == 0) {
        return;
    }
    int i = 0;
    while(i < root->size && root->minheap[i] != value){
        i++;
    }

    if(i == root->size) {
        return; // Value not found, nothing to delete
    }

    root->minheap[i] = root->minheap[root->size - 1];
    root->size--;

    // Heapify the subtree rooted at index i to restore the heap property
    heapify(root, i);
    // Heapify the parent of the deleted node if necessary
    int parent = (i - 1) / 2;
    while (i > 0 && root->minheap[i] < root->minheap[parent]) {
        swap(&root->minheap[i], &root->minheap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void print(heap *root){
    for(int i = 0; i < root->size; i++){
        printf("%d ", root->minheap[i]);
    }
    printf("\n");
}
int main()
{
    heap *root = createheap(99);
    char *choices = (char *)malloc(10 * sizeof(char));
    if (choices == NULL) {
        free(root->minheap);                
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
      else{
          continue;
      }
    }
  free(root->minheap);
  free(root);
  free(choices);
  return 0;
}
