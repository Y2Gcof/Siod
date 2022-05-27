#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void swap(int &min,int &i){
	int tmp = i;
	i = min;
	min = tmp;
}

int partition (vector<int> &arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(vector<int> &arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	unsigned long NewT(time(nullptr));
	srand(NewT);
	unsigned int start_time = clock();
	vector<int> arr;
	for(int i = 0;i<1000;i++)
	arr.push_back(1+rand()%1000);
	quickSort(arr, 0, arr.size()-1);
	cout << "Sorted array: \n";
	printArray(arr, arr.size()-1);
	cout<<endl;
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time; // искомое время
	cout<<search_time;
	return 0;
}