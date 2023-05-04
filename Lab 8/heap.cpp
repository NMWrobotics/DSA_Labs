#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  int l = 2*root + 1;
  int r = 2*root + 2;
  int largest = root;

  if(l < n && arr[l] > arr[root]){
   largest = l;
  }else largest = root;
  
  if(r < n && arr[r] > arr[largest]){
      largest = r;
  }

   if(largest != root){
      int temp = arr[root];
      arr[root] = arr[largest];
      arr[largest] = temp;

      heapify(arr,n,largest);    

   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = n/2-1; i >=0; i--){
         heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for(int j = n-1; j >=0; j--){

      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      
      n-=1;
      
      heapify(arr,n,0);

   }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   string input;
   vector<int> arr;

   cout << "Enter the array elements separated by spaces: ";
   getline(cin, input);

   stringstream ss(input);
   int num;
   while (ss >> num) {
      arr.push_back(num);
   }

   //int heap_arr[] = {4,17,3,12,9,6};
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   int n = arr.size();
   int heap_arr[n];

   for(int i = 0; i < n;i++){
      heap_arr[i] = arr[i]; 
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
   
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
