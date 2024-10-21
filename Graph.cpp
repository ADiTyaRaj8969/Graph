#include<iostream>
#include<queue>
using namespace std;
const int MAX_NODES=10;
bool visited[MAX_NODES];
bool adjacencyMatrix[MAX_NODES][MAX_NODES];

void BFS(int startnode, int totalnodes){
    queue<int>q;
    q.push(startnode);
    visited[startnode]= true;
    while(!q.empty()){
    int currentnode;
    currentnode=q.front();
    q.pop();
    cout<<currentnode<<" ";
    for(int i=0;i<totalnodes;i++){
        if(adjacencyMatrix[currentnode][i]==true&&!visited[i]){
            visited[i]=true;
            q.push(i);
        }
    }
    }

    }

int main(){
    int total_nodes,edges;
    cout<<"Enter the number of Nodes:-";
    cin>>total_nodes;

    cout<<"Enter the number of Edges:-";
    cin>>edges ;

    for(int i = 0;i<total_nodes;i++){
        for(int j = 0;j<total_nodes;j++){
            adjacencyMatrix[i][j]=false;

        }
    }
    cout<<"Enter the edges(u,v)"<<endl;
    for(int i = 0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adjacencyMatrix[u][v]=true;
        adjacencyMatrix[v][u]=true;

    }
    int startnode;
    cout<<"The starting node of BFS:";
    cin>>startnode;
    BFS(startnode,total_nodes);
    return 0;
}