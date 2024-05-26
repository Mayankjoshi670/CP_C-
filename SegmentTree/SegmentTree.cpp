// A segment tree is a data structure used for storing information about intervals, or segments. 
// It allows querying which of the stored segments contain a given point efficiently.
//  Here are the main characteristics and operations of a segment tree:

// Characteristics:
//  1 Structure: A segment tree is a binary tree where each node represents an interval (or segment) of an array.
// 2 Leaf Nodes: Each leaf node represents a single element of the array.
// 3 Internal Nodes: Each internal node represents the union (or combination) of its children. This could be a sum, minimum, maximum, or any associative operation.
// 4 Height: The height of the segment tree is 𝑂(log⁡𝑛) where 𝑛 is the number of elements in the array.

// Operations:

// Build: Constructing the segment tree from an array takes O(n) time.
// Query: Querying the segment tree to get information about a specific range typically takes  O(logn) time.
// Update: Updating an element in the array and adjusting the segment tree accordingly also typically takes O(logn) time.


// Common Use Cases:
// Range Sum Query: Quickly find the sum of elements in a given range.
// Range Minimum Query: Quickly find the minimum element in a given range.
// Range Maximum Query: Quickly find the maximum element in a given range.
// Dynamic Array: Support efficient updates and queries on a dynamic array.



#include<iostream>
#include<climits>
using namespace std; 
int a[100005] , seg[4*100005];
void build(int index , int low , int high){
 if(low == high){
  seg[index] = a[low] ; 
  return ; 
 }
  int mid = low+(high-low)/2 ; 
  build(2*index+1 , low, mid) ;
  build(2*index+2 , mid+1 , high);
  seg[index] =max(seg[2*index+1],seg[2*index+2]); 
}
int query(int  index , int low , int high , int l , int r ){
  if(low >= l && high <=r){
    // in the range 
    return seg[index] ;
  }
  if(high < l ||low >r ){
    // no present 
    return INT_MIN;
  }
  // if these condation do not meet that meen we are over-lapping
//  so we move in both directions
int mid = low+(high-low)/2 ; 
int left = query(2*index+1 , low , mid , l , r) ; 
int right = query(2*index+2 , mid +1 , high , l , r );
return max(left , right) ; 
}
int main(){
int n ; 
cin >> n ; 
for(int i = 0 ; i < n ; i++){
  cin >> a[i] ; 
}
build(0 , 0 , n-1) ; 

//  query 
int q ; 
cin>>q ; 
while(q--){
  int l , r ; 
  cin >> l >> r ; 
  cout <<query(0 ,0 , n-1 , l , r )<<endl ; 
}
  return 0 ;

}