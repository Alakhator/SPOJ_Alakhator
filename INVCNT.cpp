#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20,MAX=1e7+20;
int t,n,i,a[N],BIT[MAX],v;
long long ans;
typedef long long int ll;
void update(ll i,ll inc)
{
	while(i<=MAX)
	{
	BIT[i]+=inc;
	i+=(i&-i);
	}
}
ll query(ll i)
{
	ll ans=0;
	while(i)
	{
	ans+=BIT[i];
	i-=(i&-i);
	}
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	ll inv=0;
	for(i=0;i<MAX;i++) BIT[i]=0;

	for(ll i=n;i>=1;i--)
	{
	int v=query(a[i]-1);
	   cout<<v<<endl;
    inv+=v;
    update(a[i],1);
    for(int i=1;i<=8;i++)
    cout<<BIT[i]<<" ";
    cout<<endl;
	}
	cout<<inv<<endl;
	}
}
