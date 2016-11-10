#include <bits/stdc++.h>
using namespace std;

stack<int> Stk;
std::vector<bool> visited;
vector<vector<int>> g;

void topologicalShort(int node) {
    visited[node] = true;
    for(int i=0; i<g[node].size(); ++i) {
        int c = g[node][i];
        if(visited[c])
            continue;
        topologicalShort(c);
    }
    Stk.push(node);
}

int main() {
	int N, M, u, v;
	cin >> N >> M;
	visited.resize(N+1);
	g.resize(N+1);
	for(int i=0; i<M; ++i) {
	    cin >> u >> v;
	    g[u].push_back(v);
	}
	for(int i=1; i<N+1; ++i) {
	    if(visited[i])
	        continue;
	    topologicalShort(i);    
	}
    while(!Stk.empty()) {
        cout << Stk.top() << endl;
        Stk.pop();
    }
	return 0;
}
