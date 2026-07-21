class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<long long> prefix(n,0);

        int res = INT_MAX;

        int j=0;
        while(j<n){
            if(j==0) prefix[j] = nums[j];
           else prefix[j] = prefix[j-1] + nums[j];

           if(prefix[j]>=k) res = min(res,j+1);
           
           while(!deq.empty() && prefix[j]-prefix[deq.front()]>=k){
            res=min(res,j-deq.front() );
            deq.pop_front();


           }

           while(!deq.empty() && prefix[j] <= prefix[deq.back()]){
            deq.pop_back();
           }
           deq.push_back(j);

           j++;




        }
        return res == INT_MAX ? -1 : res;




    }
};