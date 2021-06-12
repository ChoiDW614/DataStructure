#include <iostream>
#include "ListBaseQueue.h"

constexpr int BUCKET_NUM    =   10;

void RadixSort(int arr[], int num, int maxLen)
{
    Queue buckets[BUCKET_NUM];
    int bi;
    int pos;
    int di;
    int divfac = 1;
    int radix;

    // Initialize 10 bucket
    for(bi=0; bi<BUCKET_NUM; bi++)
        QueueInit(&buckets[bi]);

    // Repeat as long as the length of the longest data
    for(pos=0; pos<maxLen; pos++)
    {
        // Repeat as many sorting targets
        for(di=0; di<num; di++)
        {
            // Extract Nth digit
            radix = (arr[di] / divfac) % 10;

            // Store data in buckets based on extracted numbers
            Enqueue(&buckets[radix], arr[di]);
        }

        // Repeat as many buckets
        for(bi=0, di=0; bi<BUCKET_NUM; bi++)
        {
            // Remove and save everything in the order it is stored in the bucket
            while(!QIsEmpty(&buckets[bi]))
                arr[di++] = Dequeue(&buckets[bi]);
        }

        // Increasing the number for extracting the Nth digit
        divfac *= 10;
    }
}

int main()
{
    int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

    int len = sizeof(arr)/sizeof(int);
    int i;

    RadixSort(arr, len, 5);

    for(i=0; i<len; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    return 0;
}