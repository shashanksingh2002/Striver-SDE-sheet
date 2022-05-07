Problem Statement
Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. 
Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array.
You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.

For example:
‘ARR1’ = [3 6 9 0 0]
‘ARR2’ = [4 10]
After merging the ‘ARR1’ and ‘ARR2’ in ‘ARR1’. 
‘ARR1’ = [3 4 6 9 10]
**************************************************************************************************************************************************
APPROACH 1:
* Create a new array of size n+m 
* Use 2 indexes and keep increementing if less that other element
* keep swapping if not.
  
CODE:
void merge(vector<int> arr1,int m,vector<int> arr2,int n){
  vector<int> newarr(n+m);
  int i=0,j=0,k=0;
  while(i<m && j<n){
    if(arr1[i]<arr2[j]){
      newarr[k++] = arr1[i++];
    }
    else{
      newarr[k++] = arr2[j++];
    }
  }
  while(i<m) newarr[k++] = arr1[i++];
  while(j<n) newarr[k++] = arr2[j++];
}

TC: O(n+m)
SC: O(n+m)
 
***************************************************************************************************************************************************

APPROACH 2:(without extra space)
* In arr1 extra space will be provided
* Use the same technique of swapping if position not correct
* After swapping check in arr2 if position correct
* If not correct use insertion sort technique to place it in correct position

CODE:
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=0, j=0;
	while(i < m and j < n){
		if(arr1[i] > arr2[0]){
			swap(arr1[i],arr2[0]);
			while(j<n-1&&arr2[j]>arr2[j+1]){
				swap(arr2[j],arr2[j+1]);
				j++;
			}
			j=0;
		}
		++i;
	}
	j=0;
	while(j<n){
		arr1[i++] = arr2[j++];
	}
	return arr1;
}

SC:O(1)
TC:O(n*m)
  
*****************************************************************************************************************************************************

APPROACH 3:(GAP Technique)
* formula : ((n+m)/2)+((n+m)%2)
* Run till gap!=1
* keep swapping if swap case hits
* at the end divide gap/2
  
CODE:
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	int gap = ((n+m)/2) + ((n+m)%2);
	
	while(1){
		int i=0;
		for(int j=gap;j<m;j++,i++){
			if(arr1[i]>arr1[j]) swap(arr1[i],arr1[j]);
		}
		int j=0;
		while(i<m&&j<n){
			if(arr1[i]>arr2[j]) swap(arr1[i],arr2[j]);
			i++;
			j++;
		}
		for(i=0;j<n;j++,i++){
			if(arr2[i]>arr2[j]) swap(arr2[i],arr2[j]);
		}
		if(gap==1) break;
		gap=(gap/2)+(gap%2);
	}
	int j=0,i=m;
	while(j<n){
		arr1[i++]=arr2[j++];
	}
	return arr1;
}

TC:O(nlogn)
SC:O(1)
