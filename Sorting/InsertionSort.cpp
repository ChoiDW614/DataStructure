/*
#include <iostream>

void InserSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n; i++)
    {
        temp = arr[i];

        for(j=i-1; j >= 0; j--)
        {
            if(temp < arr[j])
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[5] = {5, 3, 2, 4, 1};
    int i;

    InserSort(arr, sizeof(arr)/sizeof(int));

    for (i=0; i<5; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    return 0;
}
 */