// Name: Dhrumit Savaliya
// Class (CECS 325-02)
// Project Name: Prog 4 - SortRace using pthreads
// Due Date: 10/24/2023
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <string>
#include <thread> 
#include <iostream>
#include <fstream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int x, int exp)
{
 
    int output[x];
    int i, count[10] = { 0 };
 
    for (i = 0; i < x; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = x - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < x; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void merge(int *a1, int sz1, int *a2, int sz2) {
    int i = 0, j = 0, k = 0;
    int result[sz1+sz2];

    while (i < sz1 && j < sz2) {
        if (a1[i] <= a2[j]) {
            result[k] = a1[i];
            i++;
        } else {
            result[k] = a2[j];
            j++;
        }
        k++;
    }

    while (i < sz1) {
        result[k] = a1[i];
        i++;
        k++;
    }

    while (j < sz2) {
        result[k] = a2[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        a1[i] = result[i];
    }
}


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Please provide input and output filenames.\n";
        cout << "Example: ./mysort numbers.dat mysort.out\n";
        
        exit(EXIT_SUCCESS);
    }

    for(int i=0; i<argc; i++)
    {
        cout << "argv["<<i<<"]:" << argv[i]<<endl;
    }

    const int MAX = 1000000;
    ofstream fout;
    ifstream fin;
    int n;
    int arr[MAX];

    fin.open(argv[1]);
    int index = 0;
    while (fin >> n)
    {
        arr[index++] = n;
    }


    int *ptr1 = arr;
    int *ptr2 = arr+125000;
    int *ptr3 = arr+250000;
    int *ptr4 = arr+375000;
    int *ptr5 = arr+500000;
    int *ptr6 = arr+625000;
    int *ptr7 = arr+750000;
    int *ptr8 = arr+875000;

    thread thread1(radixSort,&arr[0],125000);
    thread thread2(radixSort,&arr[125000],125000);
    thread thread3(radixSort,&arr[250000],125000);
    thread thread4(radixSort,&arr[375000],125000);
    thread thread5(radixSort,&arr[500000],125000);
    thread thread6(radixSort,&arr[625000],125000);
    thread thread7(radixSort,&arr[750000],125000);
    thread thread8(radixSort,&arr[875000],125000);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    merge(arr       ,125000,arr+125000,125000);
    merge(arr+250000,125000,arr+375000,125000);
    merge(arr+500000,125000,arr+625000,125000);
    merge(arr+750000,125000,arr+875000,125000);
    
    merge(arr       ,250000,arr+250000,250000);
    merge(arr+500000,250000,arr+750000,250000);

    merge(arr,500000,arr+500000,500000);


    for (int i = 0; i < MAX; i++)
    {
        cout << arr[i] << endl;
    }
    return 0; 
}