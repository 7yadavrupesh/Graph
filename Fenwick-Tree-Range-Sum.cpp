#include <bits/stdc++.h>
using namespace std;

void update(int BIT[], int x, int val, int n) {
    for(; x<=n; x+=x&(-x)){
        BIT[x]+=val;
    }
}

int query(int BIT[], int x) {
    int sum=0;
    for(; x>0; x-=x&(-x)) {
        sum+=BIT[x];
    }
    return sum;
}

int main() {
    int N, Q, range;
    
    cin >> N;
    int arr[N+1];
    int *BIT = (int*)calloc(N+1,sizeof(int));;

    for(int i=1; i<N+1; ++i) {
        cin >> arr[i];
        update(BIT, i, arr[i], N);
    }
    cin >> Q; // number of query
    
    while(Q--) {
        cin >> range;
        cout << query(BIT,range) << endl;
    }
	return 0;
}
