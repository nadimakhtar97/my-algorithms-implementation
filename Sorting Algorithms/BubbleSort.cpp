#include<bits/stdc++.h>
using namespace std;


// time complexity = O(n^2)

void bubbleSort(vector<int>& A){

    int n = A.size();

    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }



}


int main(){

    vector<int> A = {2,7,4,1,5,3};
    bubbleSort(A);
    for(auto a : A)
        cout<<a<<" ";

    return 0;
}