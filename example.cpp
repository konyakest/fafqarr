#include<bits/stdc++.h>
#include"fafqarr.h"
using namespace std;
#define F(i,j,k) for(int i=j;i<=k;i++)
fafqarr<long long,(int)5e5+5> q;
int n,m,x,y,k,op;
int main(){
    cin>>n>>m;
    F(i,1,n) cin>>x,q[i]=x;
    F(i,1,m) {
        cin>>op>>x>>y;
        if(op==1) cin>>k,q(x,y)+=k;
        else cout<<q(x,y)<<endl;
    }
    return 0;
}
