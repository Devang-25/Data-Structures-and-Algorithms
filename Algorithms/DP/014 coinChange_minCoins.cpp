#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//int ans(vector<int> v, int n, int val){
//
//    if(n==0)
//        return INT_MAX-1;
//
//    if(val==0)
//        return 0;
//    if(val<=0)
//        return INT_MAX-1;
//    if(v[n-1]<=val){
//        return min(1+ans(v, n, val-v[n-1]), ans(v, n-1, val));
//    }else{
//        return ans(v, n-1, val);
//    }
//
//    return -1;
//}
lli dpSolution(vector<lli> v, lli n, lli val){

    lli arr[n+1][val+1] = {-1};

    for(lli i=0; i<=n; i++)
        arr[i][0] = 0;
    for(lli i=1; i<=val; i++)
        arr[0][i] = INT_MAX-1; // to prevent integer overflow
    for(lli i=1; i<=n; i++){
        for(lli j=1; j<=val; j++){

            if(v[i-1]<=j)
                arr[i][j] = min(1+arr[i][j-v[i-1]], arr[i-1][j]);
            else
                arr[i][j] = arr[i-1][j];

        }
    }
    if(arr[n][val]>=INT_MAX-1) // means not possible
        return -1;
    return arr[n][val];

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        lli val, n; cin>>val>>n;
        vector<lli> v(n);
        for(lli j=0; j<n; j++)
            cin>>v[j];
        cout<<dpSolution(v, n, val)<<endl;


    }



return 0;
}


