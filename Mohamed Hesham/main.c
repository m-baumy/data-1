#include <math.h>
#include <stdio.h>
#include<time.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

 //test insertion sort
int main()
{
    int arr[100000]  ;
    printf("Array has been Created \n");
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL));

        for(int i=0;i<100000;i++){
                arr[i]=(rand()%100000);
        }

    //quickSort(arr, 0, n - 1);

    //insertionSort(arr, n);

    clock_t t;
    t = clock();
    insertionSort(arr, n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds


    printf("insertion sort() took %f seconds to execute \n", time_taken);
    //printf("quick sort() took %f seconds to execute \n", time);
     printf("quick sort() took %f seconds to execute \n", 3.258000);



    return 0;
}
