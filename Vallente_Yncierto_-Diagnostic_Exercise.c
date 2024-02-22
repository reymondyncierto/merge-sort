#include <stdio.h>
#include <stdlib.h>

//merge a[lower] to a[mid] with a[mid+1] to a[upper] inclusive

void merge(int a[], int lower, int mid, int upper) {
    int *temp, i, j, k;
    temp = (int *)malloc((upper-lower+1)*sizeof(int));

    for (i=0, j=lower, k=mid+1; j<=mid || k<=upper; i++) {
        temp[i] = (j <= mid && k <= upper) ? a[j++] : a[k++];

    }

    for(i=0, j=lower;j<=upper; i++, j++) {
        a[j] = temp[i];
        free(temp);
    }

   
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
    return 0;
 }

