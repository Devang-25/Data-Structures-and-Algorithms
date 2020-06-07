#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int dist(p p1, p p2){
    return pow(p1.first-p2.first,2)+pow(p1.second-p2.second, 2);
}
// sorts points in increasing order of y coordinate. incase of ties, increasing order of x
bool myComparator1(p p1, p p2){

    if(p1.second<p2.second)
        return true;
    else if(p1.second>p2.second)
        return false;
    return p1.first<p2.first;

}
// sort points in increasing order of polar angle from a fixed point
// incase of ties, closer point is comes first
class myComparator2{

    p p_;
public:
    myComparator2(p p_){
        this->p_ = p_;
    }
    bool operator()(p p1, p p2){

        int val = (p2.second-p_.second)*(p1.first-p_.first) - (p1.second-p_.second)*(p2.first-p_.first);

        if(val>0)
            return true;
        else if(val<0){
            return false;
        }
        if(dist(p_, p1)<dist(p_, p2))
            return true;
        else
            return false;

    }

};

// returns true if p2 lies on left of line joining p0 and p1
int orientation(p p0, p p1, p p2){

    int val = (p2.second-p0.second)*(p1.first-p0.first) - (p1.second-p0.second)*(p2.first-p0.first);

    if(val>0)
        return 1;
    else if(val<=0){
        return 0;
    }
}
vector<p> grahamScan(vector<p> points){


    // sort in increasing order of y-coordinate
    sort(points.begin(), points.end(), myComparator1);


    // sort points in increasing order of polar angle w.r.t. to points[0]
    // if polar angle is same then low dist comes first
    sort(points.begin(), points.end(), myComparator2(points[0]));


    // if many same polar angle points are found, only keep the farthest one
    // TODO
    // if new size less than 3, no hull is possible
    for(auto i = points.begin(); i!=points.end(); i++){

        p p0 = points[0];
        p p1 = *(i-1);
        p p2 = *i;
        int val = (p2.second-p0.second)*(p1.first-p0.first) - (p1.second-p0.second)*(p2.first-p0.first);
        if(val==0)
            points.erase(i-1);


    }


    stack<p> hull;
    hull.push(points[0]); // the bottom left point will be in hull
    hull.push(points[1]);
    hull.push(points[2]);

    for(int i=3; i<points.size(); i++){



        p p1 = hull.top(); hull.pop();
        p p2 = hull.top(); hull.pop();

        // p[i] lies on left of line joining p1 and p2. So sure that p2 is in hull
        if(orientation(p2, p1, points[i])){
            hull.push(p2);
            hull.push(p1);
            hull.push(points[i]);
        }else{ // sure that p2 is not in hull
            hull.push(p1);
            hull.push(points[i]);
        }

    }


    vector<p> hull_;
    while(!hull.empty()){
        hull_.push_back(hull.top());
        hull.pop();
    }

    reverse(hull_.begin(), hull_.end());
    return hull_;


}
int main(){

//    int n; cin>>n;
//    vector<p> points(n);
//    for(int i=0; i<n; i++){
//        int x,y; cin>>x>>y;
//        points[i] = {x, y};
//    }

    vector<p> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    vector<p> hull = grahamScan(points);
    for(auto i:hull)
        cout<<i.first<<" "<<i.second<<endl;



return 0;
}
