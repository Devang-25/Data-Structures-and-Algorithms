
#include<bits/stdc++.h>
using namespace std;

int ansUtil(vector<int> v, int b, int n){

    if(b==0||n==0)
        return 0;

    if(v[n-1]<=b)
        return max(1+ansUtil(v, b-v[n-1], n-1),
                   ansUtil(v, b, n-1));
    else return ansUtil(v, b, n-1);

}
int ans(vector<int> v, int b){

    return ansUtil(v, b, v.size());

}
int main(){

//    int t; cin>>t;
//    for(int i=0; i<t; i++){
//
//        int n, b; cin>>n>>b;
//        vector<int> v(n);
//        for(int j=0; j<n; j++)
//            cin>>v[j];
//        cout<<"Case #"<<i+1<<": "<<ans(v, b)<<endl;
//    }
    string str1 = to_string(3)+to_string(30);
    string str2 = to_string(30)+to_string(3);
    cout<<str1<<" "<<str2<<" "<<(str1>str2)<<endl;


return 0;
}
