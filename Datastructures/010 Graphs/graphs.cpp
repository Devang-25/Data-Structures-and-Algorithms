#include<bits/stdc++.h>
using namespace std;

class graph{

    int v; // number of vertices
    int e=0; // number of edges
    list<int>* adj; // adjacency list pointer, which will point to array of lists

public:
    graph(int v){
        this->v = v;
        adj = new list<int>[v]; // pointer points to dynamically created array of lists
    }
    int getEdges(){
        return e;
    }
    void addEdge(int u, int v){
        adj[u].push_back(v); // add v to u's list
        adj[v].push_back(u); // incase of directed graph, comment this
        e++;
    }
    void bfs(int s){ // s is the starting point for bfs

        bool* visited = new bool[v]; // visited array for vertices
        for(int i=0; i<v;i++){
            visited[i]=false;
        }

        queue<int> q; // declare a queue
        cout<<s<<" ";
        visited[s] = true; // visited the starting vertex
        q.push(s); // push it in queue

        while(!q.empty()){
            s = q.front();
            q.pop();

            for(auto i:adj[s]){
                if(visited[i]==false){
                    cout<<i<<" ";
                    visited[i]=true;
                    q.push(i);
                }
            }

        }

    }
    void dfs(int s){

        static bool* visited = new bool[v]{false};

        if(visited[s]==false){
            cout<<s<<" ";
            visited[s]=true;
            for(auto i:adj[s]){
                if(!visited[i]){
                    dfs(i);
                }
            }
        }


    }


};
int main(){

    graph g(4); // declare a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(2);
    cout<<endl;
    g.dfs(2);
    cout<<endl;
    cout<<g.getEdges()<<endl;



return 0;
}

