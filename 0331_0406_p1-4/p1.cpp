#include <iostream>
using namespace std;


int printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArray(int arr[], int n){
    int temp;
    int minIndex = 0;
    
    for(int i = 0; i < n; i++){
        int _min = 99999;
        for(int j = i; j < n; j++){
            if(arr[j] < _min){
                _min = arr[j];
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}


int main(){
    int _size;
    int arr[100];

    cout << "Enter the size of the array: ";
    cin >> _size;
    for(int i = 0; i < _size; i++){
        cout << "Enter the " << i << "th element: ";
        cin >> arr[i];
    }

    cout << "The original array is: ";
    printArray(arr, _size);

    sortArray(arr, _size);
    cout << "The sorted array is: ";
    printArray(arr, _size);
}