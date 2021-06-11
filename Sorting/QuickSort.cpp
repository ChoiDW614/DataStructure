#include <iostream>
using namespace std;

void swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int midOfNumber(int arr[], int left, int right)
{
    int mid = (left+right)/2;
    if(arr[left] > arr[mid])
        swap(arr, left, mid);
    if(arr[mid] > arr[right])
        swap(arr, mid, right);
    if(arr[left] > arr[mid])
        swap(arr, left, mid);

    return mid;
}

int Partition(int arr[], int left, int right)
{
    int pidx = midOfNumber(arr, left, right);
    int pivot = arr[pidx];

    int low = left + 1;
    int high = right;

    swap(arr, left, pidx);

    cout << "pivot: " << pivot << endl;

    while(low <= high)
    {
        while(pivot >= arr[low] && low <=right)
        {
            low++;
        }

        while(pivot <= arr[high] && high >=(left + 1))
        {
            if(pivot == arr[high])
                break;
            high--;
        }

        if(low <= high)
            swap(arr, low, high);
    }

    swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main()
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15};

    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, len-1);

    for(i=0; i<len; i++)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
    return 0;
}