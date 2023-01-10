class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	   if(n==1) return -1;
	   int largest = INT_MIN,secondLargest = INT_MIN-1;
	   for(int i=0;i<n;i++){
	       if(arr[i]>largest){
	           swap(largest,secondLargest);
	           largest = arr[i];
	       }
	       else if(arr[i]>secondLargest && largest != arr[i]) secondLargest = arr[i];
	   }
	   return secondLargest=(largest == secondLargest || secondLargest==INT_MIN)? -1:secondLargest;
	}
};
