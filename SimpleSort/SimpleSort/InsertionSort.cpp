#include <iostream>

void InsertionSort(int* arr, int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (insData < arr[j]) {
				arr[j + 1] = arr[j];
			}
			else
				break;
		}
		arr[j+1] = insData;
	}
}

int main()
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	return 0;
}