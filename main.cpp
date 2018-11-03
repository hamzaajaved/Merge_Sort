#include<iostream>
#include <stdlib.h>
using namespace std;

void MergeSort(int Array[],int size);
void Merge(int Array[], int left[],int leftLength, int right[], int rightLength);
void printArray(int A[],int size);
int main(int argc, char const *argv[])
{
  
  int Array[] = {2,4,1,6,8,5,3,7};
  int left[] = {1,2,4,6};
  int right[] = {3,5,7,8};

  int size = (sizeof(Array) / sizeof(Array[0]));
  printArray(Array,size);

  MergeSort(Array,size);

  printArray(Array,size);
  system("pause");
  return 0;
}

void MergeSort(int Array[],int size){
  if(size < 2){
    return;
  }else{
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    
    for(int i = 0; i < mid; i++){
      left[i] = Array[i];
    }

    // printArray(left,mid);

    for(int j = 0; j < size-mid; j++){
      right[j] = Array[j+mid];
    }

    // printArray(right,size-mid);

    MergeSort(left,mid);
    MergeSort(right,size - mid);
  
    Merge(Array,left,mid,right,size - mid);
    // printArray(Array,size);
  }
}

void Merge(int Array[], int left[],int leftLength, int right[], int rightLength){
  int i = 0;
  int j = 0;
  int k = 0;

  while(i < leftLength && j < rightLength){
    if(left[i] < right[j]){
      Array[k] = left[i];
      i++;
    }else if(right[j] < left[i]){
      Array[k] = right[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of left[i] && right[j]
  while(i < leftLength){
    Array[k] = left[i];
    i++;
    k++;
  }
  while(j < rightLength){
    Array[k] = right[j];
    j++;
    k++;
  }

}

void printArray(int A[],int size){
  for(int i = 0; i < size; i++){
    cout << A[i] << " ";
  }
  cout << endl;
}