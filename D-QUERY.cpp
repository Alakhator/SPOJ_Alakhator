#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define maxn 300010;
ll sqn;
bool cmp(pair<ll,pair<ll,ll>>p1,pair<ll,pair<ll,ll>>p2)
{
    ll p=p1.first/sqn;
    ll w=p2.first/sqn;
    if(p<w)
    return true;
    else if(p>w)
    return false;
    else
    return p1.second.first<p2.second.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    sqn=sqrt(n);
    ll a[maxn];
    ll max=INT_MIN;
    for(ll i=0;i<n;i++)
    {
    scanf("%lld",&a[i]);
    if(max<a[i])
    max=a[i];
    }
    ll F[max+1]={0};
    ll q;
    scanf("%lld",&q);

    vector<pair<ll,pair<ll,ll>>>vect;
    for(ll i=0;i<q;i++)
    {
    ll t,o;
    scanf("%lld",&t);
    scanf("%lld",&o);

    ll h=(t-1);
    vect.push_back(make_pair(h,make_pair(o-1,i)));
    }
    sort(vect.begin(),vect.end(),cmp);
    ll l=0;
    ll r=-1;
    ll dc=0;
    ll dc1[q]={0};

    for(ll i=0;i<q;i++)
    {
    while(r<vect[i].second.first)
    {
    r++;
    F[a[r]]++;
    if(F[a[r]]==1)
    dc++;
    //cout<<dc<<" ";
    }
    while(r>vect[i].second.first)
    {
    F[a[r]]--;
    if(F[a[r]]==0)
    dc--;
    r--;
    //cout<<dc<<" ";
    }
    while(l<vect[i].first)
    {
    F[a[l]]--;
    if(F[a[l]]==0)
    dc--;
    l++;
    //cout<<dc<<" ";
    }
    while(l>vect[i].first)
    {
    l--;
    F[a[l]]++;
    if(F[a[l]]==1)
    dc++;
    //cout<<dc<<" ";
    }
    dc1[vect[i].second.second]=dc;
    }
    for(ll i=0;i<q;i++)
    {
    printf("%lld\n",dc1[i]);

    }
}
