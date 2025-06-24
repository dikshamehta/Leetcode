class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // making first array to be smaller always 
        // because we will appy binary search on smaller array that way
        if(n1>n2) return findMedianSortedArrays(nums2, nums1); 

        int low = 0;
        int high = n1;

        // defining where we need to put the divide line
        // basically number of element we require in the left
        int left = (n1+n2+1)/2; 

        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;
            int n = n1+n2;

            // doing this to make sure we do not go out of bound
            // eg: n1=2, n2=1 -> left=2 -> mid1=0 -> mid2=2(out of bound)
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            // so in case of out of bound we let the num be INT_MAX or MIN and compare with that below
            if(mid1<n1) r1 = nums1[mid1];
            if(mid2<n2) r2 = nums2[mid2];

            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2 == 0){
                    // if even
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                } 
                else return max(l1, l2); // if odd
            }
            else if(l1>r2) high = mid1 - 1;
            else low = mid1 + 1;

        }

        return 0;
    }
};