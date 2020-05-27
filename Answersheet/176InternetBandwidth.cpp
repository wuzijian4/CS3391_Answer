#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define N 110
int f[N][N],c[N][N],a[N],p[N];
//a数组是一个递推数组,p相当于记录路径
int n,m,s,t,flow;
queue <int> q;

void EK()
{
    flow=0;
    while(!q.empty()) q.pop();
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty())
        {
            int u;
            u=q.front(); q.pop();
            for(int v=1; v<=n; v++)  //枚举所有点v; <u,v>
                if(!a[v] && c[u][v]>f[u][v])
                {
                    p[v]=u;  q.push(v);
                    a[v]=a[u]<c[u][v]-f[u][v] ? a[u] : c[u][v]-f[u][v];
                    //递推
                }
        }

        if(!a[t]) break;
        for(int u=t; u!=s; u=p[u])
        {
            f[p[u]][u]+=a[t];
            f[u][p[u]]-=a[t];
        }
        flow+=a[t];
    }
    return ;
}
int main()
{
    int T=0;
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%d%d%d",&s,&t,&m);
        memset(p,0,sizeof(p));
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        for(int i=1 ;i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            c[u][v]+=w;          //注意建图
            c[v][u]=c[u][v];
        }
        EK();
        T++;
        printf("Network %d\n",T);
        printf("The bandwidth is %d.\n\n",flow);
    }
    return 0;
}
