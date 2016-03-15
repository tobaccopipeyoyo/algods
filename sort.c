#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int N);
void swap(int *a, int *b);
void insertionSort(int *arr, int N);
void selectSort(int *arr, int N);

void mergeSort(int *arr, int N);
void sort(int *arr, int lo, int hi);
void merge(int *arr, int lo, int mid, int hi);

int main(){
	int arr[10] = {7,6,8,2,3,1,4,10,9,5};
	int marr[10] = {1,3,5,7,9,2,4,6,8,10};
	printArray(arr, 10);
	//insertionSort(arr, 10);
	//selectSort(arr, 10);
	//merge(marr, 0, 5, 10);
	mergeSort(arr, 10);
	printArray(arr, 10);
	return 0;
}

void printArray(int *arr, int N)
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int tmp;
	printf("Swap: a %d, b %d \n", *a, *b);
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void mergeSort(int *arr, int N){
	int lo, hi;
	lo = 0;
	hi = N;
	sort(arr, lo, hi);
}

void sort(int *arr, int lo, int hi)
{
	int mid;
	if (lo == hi){
		return;
	}
	mid = (lo + hi)/2;
	if (mid == lo){
		return;
	}
	sort(arr, lo, mid);
	sort(arr, mid, hi);
	merge(arr, lo, mid, hi);	
}

void merge(int *arr, int lo, int mid, int hi)
{
	int *m, *n;
	int i,j,k;
	int lim1 = mid - lo;
	int lim2 = hi - mid;
	m = (int *)malloc(sizeof(int)*(mid-lo));
	n = (int *)malloc(sizeof(int)*(hi-lo));
	for (i = 0; i < lim1; i++){
		//printf("%d ", arr[lo + i];
		m[i] = arr[lo + i];
	}
	//printf("\n");
	for (i = 0; i < lim2; i++){
		//printf("%d ", arr[mid + i];
		n[i] = arr[mid + i];
	}
	//printf("\n");
	i = 0;
	j = 0;
	k = 0;
	while (i < lim1 && j < lim2){
		if(m[i] < n[j]){
			arr[lo + k] = m[i];
			i++;
		} else {
			arr[lo + k] = n[j];
			j++;
		}
		k++;				
	}
	if (i == lim1 && j != lim2){
		while (j < lim2){
			arr[lo + k] = n[j];
			j++;
			k++;
		}
	}
	if (i != lim1 && j == lim2){
                while (i < lim1){
                        arr[lo + k] = m[i];
                        i++;
			k++;
                }
        }
	free(m);
	free(n);	
}

void insertionSort(int *arr, int N)
{
	int i, j;
	for (i = 0; i < N - 1; i++){
		for (j = i + 1; j > 0; j--){
			if (arr[j] < arr[j-1]){
				//printf("Index j %d, j-1 %d \n", j, j-1);
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

void selectSort(int *arr, int N)
{
	int i, j;
	int min = 0;
	for (i = 0; i < N - 1; i++){
		min = i;
		for(j = i + 1; j < N; j++){
			if(arr[j] < arr[min])
				min = j;
		}
	printf("Swap index, i %d, min %d\n", i, min);
	swap(&arr[i], &arr[min]);
	}
}
