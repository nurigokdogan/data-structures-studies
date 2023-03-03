// (1-500 aralığında) Rastgele üreteceğiniz 1000 adet sayısal değeri sıralama algoritmaları ile 
// sıralayarak her algoritma için sıralama zamanlarını “dakika:saniye:salise” olarak ekrana yazan C programı 

#include<stdio.h>
#include<time.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>


void printArray(int arr[])
{
    int i;
    for (i=0; i < 1000; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double modAl(double a, double b) 
{ 
    double mod;
    
    if (a < 0) 
        mod = -a; 
    else
        mod =  a; 
    if (b < 0) 
        b = -b; 
  while (mod >= b) 
        mod = mod - b; 
  if (a < 0) 
        return -mod; 
  
    return mod; 
} 

int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == arr[mid])
        return mid+1;

    if(item > arr[mid])
        return binarySearch(arr, item, mid+1, high);
    return binarySearch(arr, item, low, mid-1);
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[])
{
	double time, saniye1,salise1,dakika,salise,saniye;
	time = (int)clock();
	time = time / CLOCKS_PER_SEC;
	
    int i, j, min_idx;
    
	for (int i = 0; i < 1000; i++) {
		arr[i] = (rand() % 500);
	}
    for (i = 0; i < 1000-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < 1000; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
    saniye1 = ((((double)clock()) / CLOCKS_PER_SEC) - time);
	salise1 = saniye1 * 60;
	salise = modAl(salise1, 60.0);
	saniye1 = (salise1-salise) / 60;
	saniye = modAl(saniye1, 60.0);
	dakika = (saniye1 - saniye)/60;
	printf("%.2f dakika : %.3f saniye : %.4f salise \n", dakika, saniye, salise);

}


void bubbleSort(int arr[]) {
	double time, saniye1,salise1,dakika,salise,saniye;
	time = (int)clock();
	time = time / CLOCKS_PER_SEC;
	int temp;
	for (int i = 0; i < 1000; i++) {
		arr[i] = (rand() % 500);
	}
	for (int i = 0; i < 1000-1; i++) {
	
		for (int j = i + 1; j < 1000; j++) {
			if (arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	saniye1 = ((((double)clock()) / CLOCKS_PER_SEC) - time);
	salise1 = saniye1 * 60;
	salise = modAl(salise1, 60.0);
	saniye1 = (salise1-salise) / 60;
	saniye = modAl(saniye1, 60.0);
	dakika = (saniye1 - saniye)/60;
	printf("%.2f dakika : %.3f saniye : %.4f salise \n", dakika, saniye, salise);

}


void binaryInsertionSort(int arr[])
{
	double time, saniye1,salise1,dakika,salise,saniye;
	time = (int)clock();
	time = time / CLOCKS_PER_SEC;
	
    int i, loc, j, selected;

	for (int i = 0; i < 1000; i++) {
		arr[i] = (rand() % 500);
	}

    for (i = 1; i < 1000; ++i)
    {
        j = i - 1;
        selected = arr[i];
        loc = binarySearch(arr, selected, 0, j);

        while (j >= loc)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = selected;
    }
    saniye1 = ((((double)clock()) / CLOCKS_PER_SEC) - time);
	salise1 = saniye1 * 60;
	salise = modAl(salise1, 60.0);
	saniye1 = (salise1-salise) / 60;
	saniye = modAl(saniye1, 60.0);
	dakika = (saniye1 - saniye)/60;
	printf("%.2f dakika : %.3f saniye : %.4f salise \n", dakika, saniye, salise);

}

void straightInsertionSort(int arr[]) {
	
	double time, saniye1,salise1,dakika,salise,saniye;
	time = (int)clock();
	time = time / CLOCKS_PER_SEC;
	
    int i = 1, j, k = 0;
    int temp;
    
    for (int i = 0; i < 1000; i++) {
		arr[i] = (rand() % 500);
	}
    
    while (i < 1000) {
        j = i - 1;
        temp = arr[j + 1];
        k = i;
        while (j >= 0) {
            if (temp < arr[j]) {
                k = j;
                j--;
            } else {
                break;
            }
        }
        j = i;
        while (j > k) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
        i++;
    }
    
     saniye1 = ((((double)clock()) / CLOCKS_PER_SEC) - time);
	salise1 = saniye1 * 60;
	salise = modAl(salise1, 60.0);
	saniye1 = (salise1-salise) / 60;
	saniye = modAl(saniye1, 60.0);
	dakika = (saniye1 - saniye)/60;
	printf("%.2f dakika : %.3f saniye : %.4f salise \n", dakika, saniye, salise);
}

void insertionSort(int arr[])  
{  
	double time, saniye1,salise1,dakika,salise,saniye;
	time = (int)clock();
	time = time / CLOCKS_PER_SEC;

    int i, key, j;  
    
    for (int i = 0; i < 1000; i++) {
		arr[i] = (rand() % 500);
	}
    
    for (i = 1; i < 1000; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
    saniye1 = ((((double)clock()) / CLOCKS_PER_SEC) - time);
	salise1 = saniye1 * 60;
	salise = modAl(salise1, 60.0);
	saniye1 = (salise1-salise) / 60;
	saniye = modAl(saniye1, 60.0);
	dakika = (saniye1 - saniye)/60;
	printf("%.2f dakika : %.3f saniye : %.4f salise \n", dakika, saniye, salise);
}  


int main()
{
    int arr[999];

straightInsertionSort(arr) ;
printArray(arr);

    return 0;
}



