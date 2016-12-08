
/* Minimum Range Query using segment tree */


#include <iostream>
const int MAX = 1000;
int Ai[MAX]
int tree[MAX*4];

void update(int node, int start, int end, int id, int val) {
	if(start == end) {
		Ai[id] = val;
		tree[node] = val;
	}else{
		int mid = (start+end)/2;
		if(start<= id && id <= end)
			update(2*node+1, start, mid, id, val);
		else
			update(2*node+2, mid+1, end, id, val);
		
		tree[node] = min(tree[2*node+1], tree[2*node+2]);
	}
}

void build(int node, int start, int end) {
	if(start == end){
		tree[node] = Ai[start];
		return ;
	}
	
	int mid = (start+end)/2;
	build(2*node+1, start, mid);
	build(2*node+2, mid+1, end);
	
	tree[node] = min(tree[2*node+1], tree[2*node+2]);
}

int query(int node, int start, int end, int l, int r) {
	if(r<start || end<l)
		return MAX_INT;
	if(l<= start && end <=r )
		return tree[node];
	int mid = (start+end)/2;
	int p1 = query(2*node+1, start, mid, l, r);
	int p2 = query(2*node+2, mid+1, end, l, r);
	
	return min(p1,p2);
}
	
