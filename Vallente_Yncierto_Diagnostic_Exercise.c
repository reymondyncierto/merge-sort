#include <stdio.h>
#include <stdlib.h>

int * read_file(char *filename, int *size) {
    FILE *file;
    file = fopen(filename, "r");
    // read the size of the array
    fscanf(file, "%d", size);
    // allocate memory for the array
    int *arr = (int *)malloc(*size * sizeof(int));
    // read the elements of the array
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    return arr;
}

//merge a[lower] to a[mid] with a[mid+1] to a[upper] inclusive
void merge(int a[], int lower, int mid, int upper) {
    int *temp, i, j, k;
    temp = (int *)malloc((upper-lower+1)*sizeof(int));

    for (i=0, j=lower, k=mid+1; j<=mid || k<=upper; i++) 
        temp[i] = (j<=mid && (k>upper || a[j] < a[k])) ? a[j++] : a[k++];

    for(i=0, j=lower;j<=upper; i++, j++) 
        a[j] = temp[i];
    
    free(temp);   
}

 //merge sort from a[lower] to a[upper] inclusive
 void merge_sort(int a[], int lower, int upper) {
    int mid;

    if (upper-lower>0) {
        mid = (lower+upper)/2;
        merge_sort(a, lower, mid);
        merge_sort(a, mid+1, upper);
        merge(a, lower, mid, upper);
    }
 }

 int main() {
    int size;
    int *arr = read_file("Vallente_Yncierto_values.txt", &size);

    merge_sort(arr, 0, size-1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
 }