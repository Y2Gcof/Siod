#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int FibonacciSearch(vector<int> &arr, int x, int size)
{

    int fM2 = 0;
    int fM1 = 1;
    int fibM = fM2 + fM1;
    while (fibM < size) {
        fM2 = fM1;
        fM1 = fibM;
        fibM = fM2 + fM1;
    }
    int o = -1;
    while (fibM > 1) {
        int i = min(o + fM2, size - 1);
        if (arr[i] < x) {
            fibM = fM1;
            fM1 = fM2;
            fM2 = fibM - fM1;
            o = i;
        }
        else if (arr[i] > x) {
            fibM = fM2;
            fM1 = fM1 - fM2;
            fM2 = fibM - fM1;
        }
        else
            return i;
    }
    if (fM1 and arr[o + 1] == x)
        return o + 1;
    return -1;
}

int main()
{
    unsigned long NewT(time(nullptr));
    srand(NewT);
    unsigned int start_time = clock();
    vector<int> arr;
    for(int i = 0;i<100000;i++)
        arr.push_back(1+rand()%100000);
    sort(arr.begin(),arr.end());
    int x = 999;
    int ind = FibonacciSearch(arr, x, arr.size());
    if(ind>=0)
        cout<<"Found at index: "<<ind<<endl;
    else
        cout<<"not found"<<x<<endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time; // искомое время
    cout<<search_time;
    return 0;
}
