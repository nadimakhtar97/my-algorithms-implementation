#include<bits/stdc++.h>
using namespace std;


// In selection sort we are selecting the min element and 
// swapping with the first element and then selecting the
// second min element and swapping with second first element
// and so on.


// time complexity = O(n^2)

void selectionSort(vector<int>& A){

    int n = A.size();

    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if( A[j] < A[minIndex]){
                swap(A[j],A[minIndex]);
            }
        }

    }

}


int main(){

    vector<int> A = {2,7,4,1,5,3};
    selectionSort(A);
    for(auto a : A)
        cout<<a<<" ";

    return 0;
}