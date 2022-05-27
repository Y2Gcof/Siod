#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void merge(vector<int> &array, int left, int mid, int right)
{
    int MArrayOne = mid - left + 1;
    int MArrayTwo = right - mid;
    auto *leftArray = new int[MArrayOne], *rightArray = new int[MArrayTwo];
    for (int i = 0; i < MArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < MArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < MArrayOne and indexOfSubArrayTwo < MArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < MArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < MArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int> &array, int  begin, int end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int binarySearch(vector<int> &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void printArray(vector<int> &A, int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    unsigned long NewT(time(nullptr));
    srand(NewT);
    unsigned int start_time = clock();
    vector<int> arr;
    for(int i = 0;i<1000;i++)
        arr.push_back(1+rand()%1000);
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Sorted array is \n";
    printArray(arr, arr.size());
    cout<<endl;
    int result = binarySearch(arr, 0, arr.size() - 1, 999);
    if(result == -1) cout<<"Element not found"<<endl;
    else cout << "Element " << result<<endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time; // искомое время
    cout<<"Time: "<<search_time;
    return 0;
}
