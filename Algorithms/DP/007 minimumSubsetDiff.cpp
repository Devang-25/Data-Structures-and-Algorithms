// given an array, find two subsets with minimum difference

#include<bits/stdc++.h>
using namespace std;

int minimumDiff(vector<int> v, int sum, int n){

    /*
    if(sum==0 or n==0)
        return 0
    if(v[n-1]<=sum)
        return fun(v, sum-v[n-1], n-1)||fun(v, sum, n-1)
    else
        return fun(v, sum, n-1)

    */
    bool arr[n+1][sum+1];
    for(int i=0; i<=n; i++){
        arr[i][0] = true;
    }
    for(int i=1; i<=sum; i++){
        arr[0][i] = false;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){

            if(v[i-1]<=j){
                arr[i][j] = arr[i-1][j-v[i-1]]||arr[i-1][j];
            }else{
                arr[i][j] = arr[i-1][j];
            }

        }
    }

    // last row contains possible sums by the subsets
    vector<int> temp;
    for(int i=0; i<=sum/2; i++){
        if(arr[n][i]){
            temp.push_back(i);
        }
    }

    return sum-2*(*(--temp.end()));


}
int ans(vector<int> v){
    int sum = accumulate(v.begin(), v.end(), 0);
    return minimumDiff(v, sum, v.size());
}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n;
        vector<int> v(n, 0);
        for(int j=0; j<n; j++){
            cin>>v[j];
        }
        cout<<ans(v)<<endl;
    }

return 0;
}
