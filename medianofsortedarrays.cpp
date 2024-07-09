class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int lt = l1+l2;
        double arr[lt];
        int r1 =0;
        int r2=0;
        int i=0;
        
        for(int i=0;i<lt;i++){
          
              if (r1 <l1 && r2< l2){
               if (nums1[r1]>nums2[r2]){
                   arr[i]=nums2[r2];
                   r2++;
               }
               else if (nums2[r2]>nums1[r1]){
                   arr[i]=nums1[r1];
                   r1++;
               }
               else{
                   arr[i]=nums1[r1];
                   arr[i+1]=nums1[r1];
                   r1++;
                   
               }
              }
            else if(r1<l1){
                arr[i]=nums1[r1];
                r1++;
            }
            else if(r2<l2){
                arr[i]=nums2[r2];
                r2++;
            }
        }       
        int sum;
      
        int start = 0;
        int end = lt-1;
        for (int i =0; i<lt; i++){
                if((start+1)<(lt))
                    start++;
                if(end-1>=0)
                    end--;
            
            
            if(start==end){
                return arr[start];
                    
            }
            else if (end < start){
                // - - - - - - 
                sum=(arr[start]+arr[end]);
               return sum/(double)2;
             
            }
            
        }
        return 0;
    }
};
