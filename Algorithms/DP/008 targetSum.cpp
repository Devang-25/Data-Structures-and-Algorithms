#include<bits/stdc++.h>
using namespace std;
// same as subset difference problem

int ans(vector<int> nums, int S){


    int sum = (accumulate(nums.begin(), nums.end(), 0));

    if(S>sum)
        return 0;
    sum+=S;

    if(sum%2!=0)
        return 0;

    sum = sum/2;
    int n = nums.size();
    int arr[n+1][sum+1];

    /*
    For all those stuck with the test case where in ZEROS are involved, for example in the LeetCode Problem.
    The reason is that when zeros are involved in the array the INITIALISATION part of the code changes a bit.
    For Example: When the given input is arr=[0,0,0,0,1] the 0th column in the t[n+1][sum+1] matrix will no
    longer be filled with 1's. The reason is that whenever a particular element in the array arr[i] is encountered
    to be 0, the number of subsets in that array(till length i) which would give sum =0 would no longer be 1,
    as now in addition to the empty subset we also have a subset {0} which would give subset sum=0.
    */

    arr[0][0] = 1;
    for(int i=1; i<=n; i++){
        if(nums[i-1]==0){
            arr[i][0] = 2*arr[i-1][0]; // arr[0][0] is one for empty subset. if zero is encounter then we can have empty set or 0 which will give sum equal to 0
        }else{
            arr[i][0] = arr[i-1][0]; // else the number will remain same
        }
    }
    for(int i=1; i<=sum; i++)
        arr[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(nums[i-1]<=j)
                arr[i][j] = arr[i-1][j-nums[i-1]]+arr[i-1][j];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][sum];
}

int main(){

    int n, S; cin>>n>>S;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<ans(nums, S);


return 0;
}
