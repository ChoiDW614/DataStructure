//#include <iostream>
//
//void SelSort(int* arr, int n)
//{
//	int i, j;
//	int maxIdx;
//	int temp;
//
//	for (i = 0; i < n - 1; i++) {
//		maxIdx = i;
//
//		for (j = i; j < n; j++) {
//			if (arr[maxIdx] > arr[j]) {
//				maxIdx = j;
//			}
//		}
//		temp = arr[maxIdx];
//		arr[maxIdx] = arr[i];
//		arr[i] = temp;
//	}
//}
//
//int main()
//{
//	int arr[4] = { 3, 4, 2, 1 };
//	int i;
//
//	SelSort(arr, sizeof(arr) / sizeof(int));
//
//	for (i = 0; i < 4; i++) {
//		std::cout << arr[i] << " ";
//	}
//	std::cout << std::endl;
//	return 0;
//}