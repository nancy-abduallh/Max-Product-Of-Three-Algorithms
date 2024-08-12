#include <iostream>

using namespace std;
void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];// Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];// Merge the temporary arrays back into arr[left..right] in descending order
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) // Reverse comparison condition for descending order
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }// Copy the remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];// Copy the remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}// Merge sort function to sort array in descending order
void mergeSort(int arr[], int left, int right) {
    if (left < right) {// Find the middle point
        int mid = left + (right - left) / 2;// Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);// Merge the sorted halves
        Merge(arr, left, mid, right);
    }
}
long long max_product(int arr[],int n){
    mergeSort(arr,0,n-1);
    long long maxi1=arr[0]*arr[1]*arr[2];
    long long maxi2=arr[0]*arr[n-1]*arr[n-2];
    if(maxi1>maxi2)
    return maxi1;
    else
        return maxi2;
}
int main()
{
    int n;
    cout<<"enter the number of the array grater then 3 -> ";
    cin>>n;
    if(n>=3){
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"A["<<i<<"] = ";
        cin>>arr[i];
    }
    cout<<"maximal triplet = "<<max_product(arr,n);
    }
    else
        cout<<"the minimum size is 3";
    return 0;
}
