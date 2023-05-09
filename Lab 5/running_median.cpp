#include <iostream>
using namespace std;


// functions for Quick Sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){

    const int n = 6;
    int arr[n] = {11,2,13,6,5,8};
    int newarr[n];
    float median = 0;

    cout<< "Input"<< " ";

    for (int k = 0; k<= n-1; k++){
        cout<<arr[k]<<" ";
    }

    cout<<endl;
    cout << "sorted"<< "\t\t"<< "median"<<endl;

     for (int i = 0; i<= n-1; i++){
        newarr[i] = arr[i];
        quickSort(newarr, 0, i);
        for (int j = 0; j<= i; j++){
            cout<<newarr[j]<<" ";
        }
        if ((i+1) %2 == 0) {
            //cout<<"even";
            //cout<< i;
            median = (float(newarr[i / 2]) + float(newarr[(i / 2) + 1])) / 2;
            
            cout <<"\t\t"<< median;
                
        }else{

            median = float(newarr[i / 2]);
            cout <<"\t\t"<< median;

         }
         cout<<endl; 


     }


}
