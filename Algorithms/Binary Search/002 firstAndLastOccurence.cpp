#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

pair<int, int> ans(vector<int> v, int x){

    int n = v.size();
    int start(0), last(n-1), mid;

    int first=-1;
    while(start<=last){
        mid = (start+last)/2;
        if(v[mid]==x){
            first = mid;
            last = mid-1;
        }else if(v[mid]>x){
            last = mid-1;
        }else if(v[mid]<x){
            start = mid+1;
        }
    }
    start=0; last=n-1;
    int second=-1;
    while(start<=last){
        mid = (start+last)/2;
        if(v[mid]==x){
            second = mid;
            start = mid+1;
        }else if(v[mid]>x){
            last = mid-1;
        }else if(v[mid]<x){
            start = mid+1;
        }
    }

    return {first, second};

}
int main(){

    int t; cin>>t;
    loop(i, t){

        int n, x; cin>>n>>x;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        pair<int, int> p = ans(v, x);

        if(p.first==-1)
            cout<<-1<<endl;
        else
            cout<<p.first<<" "<<p.second<<endl;



    }

}
