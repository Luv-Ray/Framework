#include<bits/stdc++.h>
#define maxn 1000010
#define maxm 10000010
#define all 1000000000
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,m,tot,root;
int a[maxn],ans[maxn],t[maxn],ls[maxm],rs[maxm],mx[maxm];
vector<pair<int,int> > ve[maxn];
void update(int x,int v)
{
    while(x) t[x]=min(t[x],v),x-=lowbit(x);
}
int ask(int x)
{
    int v=all;
    while(x<=n) v=min(v,t[x]),x+=lowbit(x);
    return v;
}
void modify(int l,int r,int pos,int v,int &cur)
{
    if(!cur) cur=++tot;
    mx[cur]=max(mx[cur],v);
    if(l==r) return;
    if(pos<=mid) modify(l,mid,pos,v,ls[cur]);
    else modify(mid+1,r,pos,v,rs[cur]);
}
int query(int L,int R,int l,int r,int cur)
{
    if(!cur) return 0;
    if(L<=l&&R>=r) return mx[cur];
    int v=0;
    if(L<=mid) v=max(v,query(L,R,l,mid,ls[cur]));
    if(R>mid) v=max(v,query(L,R,mid+1,r,rs[cur]));
    return v;
}
void clear()
{
    for(int i=1;i<=n;++i) t[i]=all;
    for(int i=1;i<=tot;++i) ls[i]=rs[i]=mx[i]=0;
    tot=root=0;
}
void work()
{
    clear();
    for(int i=1;i<=n;++i)
    {
        int pos=query(a[i],all,0,all,root);
        while(pos)
        {
            update(pos,a[pos]-a[i]);
            pos=query(a[i],(a[i]+a[pos])/2-(~(a[i]+a[pos])&1),0,all,root);
        }
        modify(0,all,a[i],i,root);
        for(int j=0;j<ve[i].size();++j)
            ans[ve[i][j].second]=min(ans[ve[i][j].second],ask(ve[i][j].first));
    }
}
int main()
{
    read(n);
    read(m);
    for(int i=1;i<=n;++i) read(a[i]);
    for(int i=1;i<=m;++i)
    {
        int l,r;
        read(l),read(r),ans[i]=all;
        ve[r].push_back({l,i});
    }
    work();
    for(int i=1;i<=n;++i) a[i]=all-a[i];
    work();
    for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}