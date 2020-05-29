#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > fun(vector<vector<int> >& mat){


    int rows = mat.size(); int cols = mat[0].size();
    vector<vector<int> > arr(mat);

    for(int i=0; i<rows; i++){
        for(int j=1; j<cols; j++){
            arr[i][j] = arr[i][j]+arr[i][j-1];
        }
    }

    for(int i=1; i<rows; i++){
        for(int j=0; j<cols; j++){
            arr[i][j] = arr[i][j]+arr[i-1][j];
        }
    }

    return arr;

}
int maxSideLength(vector<vector<int>>& mat, int threshold) {

    int rows(mat.size()), cols(mat[0].size());

    vector<vector<int> > summed = fun(mat);

    int i(0), j(cols-1);

    int ans = 0;
    while(i<rows && j>=0){

        cout<<"yes"<<endl;

        if(summed[i][j]>threshold){
            j--;
        }
        else if(summed[i][j]<threshold){
            if(i==j){
                ans = i;
            }
            i++;
        }
        else if(summed[i][j]==threshold){
            if(i==j){
                ans  = i;
                break;
            }
            else if(i>j){
                i--;
            }
            else if(i<j){
                j--;
            }
        }

    }

    return ans+1;

}


int main(){

    int rows, cols; cin>>rows>>cols;

    vector<vector<int> > v(rows, vector<int>(cols, 0));
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<cols; j++){
//            cin>>v[i][j];
//        }
//    }

    v = {{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}};

    int threshold; cin>>threshold;

//    cout<<maxSideLength(v, threshold);
    v = fun(v);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


return 0;
}
