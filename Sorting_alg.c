	/* 
	Author: Chau Nguyen 
	Course: CSE 5311 
	Date: Jan 26 2025 
	Description: Sorting Algorithm Implementation 
	DO NOT COPY WITHOUT PERMISSION 
	*/
		
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <string.h>
	#include <stdbool.h>

	
	//inst sort algor
	void insertionSort(int arr[],int n)
	{
		int i,j,k;
		int key;
		printf ("\nInsection Sort proceeding:\n");
		for (i =1; i<n;i++)
		{	
			key = arr[i];
			j = i -1;
			printf("Step %d: Inserting %d\n",i,key);
			while (j>=0 && arr[j] > key)
			{
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=key;
		}
	}

	//Sel algor
	void selectionSort(int arr[], int n)
	{
		int i,j;
		int minIdx;
		for ( i=0; i < n; i++)
		{
			minIdx=i;
			for (j=i+1;j<n;j++)
			{
				if(arr[j] <arr[minIdx])
				{
					minIdx=j;
				}
			}

			if (minIdx!=i)
			{
				int temp  =arr[minIdx];
				arr[minIdx] = arr[i];
				arr[i] = temp;
				printf ("Swapped %d with %d\n",arr[i], arr[minIdx]);
			}
		}
	}

	//bbl algor
	void bubbleSort(int arr[],int n)
	{
		printf("\nBuble Sort steps:\n");
		int swapped=0,i=0,j=0;
		for(i=0;i<n-1;i++)
		{
			swapped = 0;
			for(int j=0;j<n-i-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					int temp  = arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
					swapped=1;
					printf("Swaped %d with %d \n",arr[j],arr[j+1]);
				}
			}
			if(swapped == 0)
			{
				break;
			}
		}
	}

	void printArray(int arr[],int size)
	{
		int i=0;
		for (i=0;i<size;i++)
		{
			printf("%d\n",arr[i]);
		}
	}

double measureTime(void (*sortFunction)(int[], int), int arr[], int size, FILE *file, const char *algo) 
{
    clock_t start, end;
    start = clock();
    sortFunction(arr, size);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Save results to a file
    fprintf(file, "%d,%s,%.6f\n", size, algo, time_taken);
    return time_taken;
}

int main() {
    int sizes[] = {5, 10, 20, 100, 1000, 5000, 10000, 50000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *file = fopen("benchmark_results.csv", "w");
    fprintf(file, "Size,Algorithm,Time\n"); // CSV Header

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
		int i;
        int *arr = (int *)malloc(n * sizeof(int));

        // Generate Random Numbers
        srand(time(0));
        for (i = 0; i < n; i++) 
		{
            arr[i] = rand() % 100000;
        }

        // Sorting Tests
        int *arrCopy = (int *)malloc(n * sizeof(int));
        memcpy(arrCopy, arr, n * sizeof(int));
        measureTime(insertionSort, arrCopy, n, file, "InsertionSort");

        memcpy(arrCopy, arr, n * sizeof(int));
        measureTime(selectionSort, arrCopy, n, file, "SelectionSort");

        memcpy(arrCopy, arr, n * sizeof(int));
        measureTime(bubbleSort, arrCopy, n, file, "BubbleSort");

        free(arr);
        free(arrCopy);
    }

    fclose(file);
    printf("Benchmark completed. Results saved in benchmark_results.csv\n");
    return 0;
}




