/*
#include <iostream>

void SelSort(int arr[], int n)
{
    int i, j, k, temp;

    for(i = 0; i < n-1; i++)
    {
        k = i;

        for(j= i+1; j < n; j++)
        {
            if(arr[k] > arr[j])
                k = j;
        }

        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main()
{
    int arr[4] = {3, 4, 2, 1};
    int i;

    SelSort(arr, sizeof(arr)/sizeof(int));

    for(i = 0; i<4; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    return 0;
}
 */