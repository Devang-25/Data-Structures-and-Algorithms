class Solution {
public:
    bool isSet(int& bitmask, int i){

        if(bitmask & (1<<i) ) return true;
        else return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;

        int partitionSum = sum/k;
        vector<int> map((1<<16) + 2, -1);
        map[0] = 0;
        for(int i=0; i < (1<<nums.size()); i++){

            if(map[i]==-1) continue;
            for(int j=0; j<nums.size(); j++){

                if(!isSet(i, j) && (nums[j]+map[i])<=partitionSum)
                    map[i | (1<<j)] = (nums[j]+map[i])%partitionSum;

            }

        }

        return map[(1<<(nums.size()))-1]==0;

    }
};
