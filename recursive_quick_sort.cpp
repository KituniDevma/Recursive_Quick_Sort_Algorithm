#include <iostream>
#include <string>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

//Getting random values.
void BuiltArray(int A[], int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    for(int i = 0; i < n; i++){
        A[i] = dis(gen);
    }
}


//Partition function.
int partition (int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start;

    for (int i=start; i<end; i++){
        if (arr[i]<=pivot){
            swap(arr[i],arr[pIndex]);           //swap if the element is less than the pivot.
            pIndex++;
        }
    swap(arr[pIndex],arr[end]);
    return pIndex;
    }
}

//Quick Sort- recursive function.
void quickSort (int arr[] ,int start, int end){
    if (start >= end ){                            //Base case.
        return ;
    }
    else {
        int pIndex = partition(arr, start, end);   // Getting the pivot into it's sorted place.
        quickSort(arr, start, pIndex - 1);         // Sorting the two partioned parts recursively.
        quickSort(arr, pIndex + 1, end);
        return;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: " ;    
    cin >> size;           //Enter the nmber of elements to be sorted.
    int arr[size];
    double sum = 0;
    for (int i = 0; i < 500; i++ )
    {
    
        BuiltArray(arr, size);       // Calling BuiltArray fuction to get random elements.
    
        auto start = high_resolution_clock::now();
        quickSort(arr, 0 ,size - 1);    //Calling Quick Sort function.
        auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start);

        sum = sum + duration.count();
    }
    cout << sum/500;
    return 0;
} 
