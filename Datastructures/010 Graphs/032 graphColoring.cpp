#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int> >& graph, vector<int>& coloring, int c, int num){

    for(int i=0; i<graph.size(); i++){
        if(graph[num][i] && coloring[i]==c)
            return false;
    }

    return true;

}
bool graphColoringUtil(vector<vector<int> >& graph, vector<int>& coloring, int num){

    // base case: if all vertices are colored
    if(num==graph.size()) return true;

    for(int c=1; c<=coloring.size(); c++){

        if(isSafe(graph, coloring, c, num)){

            coloring[num] = c;
            if(graphColoringUtil(graph, coloring, num+1))
                return true;
            else
                coloring[num] = -1;

        }


    }
    return false;

}
void graphColoring(int numVertices, vector<vector<int> >& edgeList, int m){

    vector<vector<int> > graph(numVertices, vector<int>(numVertices, 0));
    for(int i=0; i<edgeList.size(); i++){
        graph[edgeList[i][0]][edgeList[i][1]] = 1;
        graph[edgeList[i][1]][edgeList[i][0]] = 1;
    }

    vector<int> coloring(m, -1);

    if(!graphColoringUtil(graph, coloring, 0))
        cout<<0;
    else
        cout<<1;
    // for(int i=0; i<m; i++)
    //     cout<<coloring[i]<<" ";

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int numVertices; cin>>numVertices;
	    int m; cin>>m;
	    int numEdges; cin>>numEdges;
	    vector<vector<int> > edgeList;
	    for(int j=0; j<numEdges; j++){
	        int u, v; cin>>u>>v;
	        edgeList.push_back({u-1, v-1});
	    }
	    graphColoring(numVertices, edgeList, m);
	    cout<<'\n';

	}
	return 0;
}
