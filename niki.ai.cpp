#include<bits/stdc++.h>
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define si(x) scanf("%d",&x)
#define pll(x) printf("%lld\n",x)
#define sll(x) scanf("%lld",&x)
#define M 1000000007
#define ll long long
using namespace std;
void mul(ll m1[3][3],ll m2[3][3],ll mod)
{
	int i,j,k;
	ll m[3][3]={{}};
	//printf("yoo\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		    m[i][j]=0;
			for(k=0;k<3;k++)
			{
				m[i][j]= (m[i][j] + (m1[i][k]*m2[k][j])%mod)%mod;
			}
		}
	}
	FOR(i,0,3)
	{
        FOR(j,0,3)
            m1[i][j]=m[i][j];//printf("%lld ",m1[i][j]);
	}
}

void pow(ll f[3][3],ll n,ll mod)
{
    if(n==0||n==1)
        return;
    ll g[3][3]={{1,1,1},{1,0,0},{0,0,1}};
    pow(f,n/2,mod);
    mul(f,f,mod);
    if(n%2)
        mul(f,g,mod);
}
ll fib(ll n,ll mod)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1;
    ll f[3][3]={{1,1,1},{1,0,0},{0,0,1}};
    ll a[3]={1,1,1};
    pow(f,n-1,mod);
   // FOR(i,0,4)
     //   printf("%lld %lld\n",a[i],f[0][i]);
    return (a[0]*f[0][0]%mod+a[1]*f[0][1]%mod+mod)%mod;
}
int main()
{
    int t;
    si(t);
    while(t--)
    {
        ll n;
        sll(n);
        cout<<fib(n+1,M)<<"\n";
    }
    return 0;
}
