#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& v, int l, int r){

    // cannot multiply single matrix
    if(l>=r)
        return 0;

    int mini = INT_MAX;
    for(int k=l+1; k<r; k++){
        int temp = ans(v, l, k)+ans(v, k+1, r)+v[l]*v[k]*v[r];
        mini = min(mini, temp);
    }

    return mini;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n; vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v, 0, n-1)<<endl;
    }


return 0;
}
