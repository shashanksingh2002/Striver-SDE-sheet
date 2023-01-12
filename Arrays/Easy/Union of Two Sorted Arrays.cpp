public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        ans.push_back(min(arr1[0],arr2[0]));
        int i=0,j=0,k=0;
        while(i<n && j<m){
           if(arr1[i]==arr2[j]){
               if(ans[k] != arr1[i]){
                  ans.push_back(arr1[i]);
                  k++;
               }
                i++;
                j++;
           }
           else if(arr1[i]<arr2[j]){
               if(ans[k] != arr1[i]){
                   ans.push_back(arr1[i]);
                   k++;
               }
               i++;
           }
           else{
               if(ans[k] != arr2[j]){
                   ans.push_back(arr2[j]);
                   k++;
               }
               j++;
           }
        }
        while(i<n){
            if(ans[k] != arr1[i]){
                ans.push_back(arr1[i]);
                k++;
            }
            i++;
        }
        while(j<m){
            if(ans[k] != arr2[j]){
                ans.push_back(arr2[j]);
                k++;
            }
            j++;
        }
        return ans;
    }
};
