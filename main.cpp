#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair< int, int >
#define MAX 1001

// ( w (u, v) )
vector< pair< int, edge > > GRAPH, MST;
int parent[MAX], total, N, E;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
}

void reset()
{
    // reset appropriate variables here

    for(int i=1; i<=N; i++) parent[i] = i;
}

void print()
{
    int i, sz;

    sz = MST.size();
    for(i=0; i<sz; i++)
    {
        cout<< MST[i].second.first;
        cout<<","<< MST[i].second.second;
        cout<<":"<< MST[i].first<<endl;
    }
   cout<<"MIN COST: "<<total<<endl;
}

int main()
{
    int i, u, v, w;
cout<<"Enter Number of Nodes : "<<endl;
    cin>>N;
    cout<<"Enter Number of Edges : "<<endl;
    cin>>E;
    reset();
    for(i=0; i<E; i++)
    {
        cout<<"Enter from  Start node\t";
        cin>>u;
         cout<<"to End node\t";
         cin>>v;
         cout<<"edge of  weight\t";
         cin>>w;
         cout<<endl;
        GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
    }
    kruskal(); // runs kruskal and construct MST vector
    print(); // prints MST edges and weights
cout<<"Enter any number to end"<<endl;
int q;
cin>>q;
    return 0;
}
