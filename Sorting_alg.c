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

double measureTime(void(*sortFunction)(int[],int),int arr[], int size)
{
	clock_t start,end;
	start = clock(); 
	sortFunction(arr,size);
	end = clock();
	return ((double)(end-start)) / CLOCKS_PER_SEC;
}


int main()
{
	int n ,choice,randomize,i;
	printf("Enter the number of Elements:");
	scanf("%d",&n);

	int *arr = (int*)malloc(n*sizeof(int));
	if (arr ==NULL)
	{
		printf("Memory allocation faliled!\n");
		return 1;
	}

	printf("Generate randome array elemetns? ---(1=Yes, 0=No):");
	scanf("%d",&randomize);
	if(randomize ==1)
	{
		
		srand(time(0));
		for(i=0;i<n;i++)
		{
			arr[i]=rand()%100;
		}
	}
	else
	{
		printf("Enter %d numbers: ",n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
	}

	printf("Input array: ");
	printArray(arr,n);
	printf("\nChoose a sorting algorithm:\n");
	printf("1.Insertion Srt\n2.Selection Srt\nBubble Srt\nEnter your choice: ");
	scanf("%d",&choice);
	int *arrCoppy=(int*)malloc(n*sizeof(int));
	if(arrCoppy ==NULL)
	{
		printf("Memory allocation faliued!\n");
		free(arr);
		return 1;
	}

	for(i=0;i<n;i++)
	{
		arrCoppy[i]=arr[i];
	}

	double timeTaken =0.0;
	switch (choice)
	{
		case 1:
			timeTaken = measureTime(insertionSort,arrCoppy,n);
			printf("\nSorted Arr (Inst Srt): ");
			break;
		case 2:
			timeTaken = measureTime(selectionSort, arrCoppy,n);
			printf("\nSorted Arr (Selct Srt): ");
			break;
		case 3:
			timeTaken = measureTime(bubbleSort,arrCoppy,n);
			printf("\nSOrted Arr (Bbl Srt): ");
			break;
		default:
			printf("Invalid, break!!!!!");
			free(arr);
			free(arrCoppy);
			return 1;
	}
	printArray(arrCoppy,n);
	printf("Excution time = %.6f Secs\n",timeTaken);
	free(arr);
	free(arrCoppy);
	return 0;
}


		




