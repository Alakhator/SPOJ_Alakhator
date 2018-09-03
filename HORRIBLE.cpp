#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void construct_tree(ll *a,ll *segment,ll low,ll high,ll pos)
{
    if(low>high)
    return;
	if(high==low)
	{
	segment[pos]=0;
    return;
    }
    ll mid=(high+low)/2;
    construct_tree(a,segment,low,mid,2*pos+1);
    construct_tree(a,segment,mid+1,high,2*pos+2);
    segment[pos]=(segment[2*pos+1]+segment[2*pos+2]);
}
void print_tree(ll *segment,ll k)
{
    cout<<endl;
	for(int i=0;i<k;i++)
	{
	cout<<segment[i]<<" ";
	}
}
ll range_sum_query(ll *segment,ll qs,ll qe,ll low,ll high,ll pos, ll *lazy){
	if(low>high)
	return 0;

	if(lazy[pos]!=0)
	{
	segment[pos]+=(high-low+1)*lazy[pos];
	if(low!=high)
	{
	lazy[2*pos+1]+=lazy[pos];
	lazy[2*pos+2]+=lazy[pos];
	}
	lazy[pos]=0;
	}


	//No Overlap
	if(qs>high || qe<low){
		return 0;
	}
	else if(low>=qs && high<=qe){
		return segment[pos];
	}
	else{
		ll mid = (low+high)/2;
		ll left = range_sum_query(segment,qs,qe,low,mid,2*pos+1,lazy);
		ll right = range_sum_query(segment,qs,qe,mid+1,high,2*pos+2,lazy);
		return (left+right);
	}
}

void update_range_lazy(ll *segment,ll low,ll high,ll rs,ll re,ll val,ll pos, ll *lazy)
{
    if(low>high)
    return;

    //settle
    if(lazy[pos]!=0)
    {
    segment[pos]+=(high-low+1)*lazy[pos];
    if(high!=low)
    {
    lazy[2*pos+1]+=lazy[pos];
    lazy[2*pos+2]+=lazy[pos];
    }
    lazy[pos]=0;
    }

    //no overlap
	if(rs>high || re<low)
	return;
    if(low==high)
    {
    segment[pos]+=(high-low+1)*val;
    return;
    }
	//complete overlap
	if(rs<=low &&  re>=high)
	{
	segment[pos]+=(high-low+1)*val;
	if(high!=low)
    {
    lazy[2*pos+1]+=val;
    lazy[2*pos+2]+=val;
    }
    lazy[pos]=0;
	return;
    }


	ll mid=(low+high)/2;
	update_range_lazy(segment,low,mid,rs,re,val,2*pos+1,lazy);
	update_range_lazy(segment,mid+1,high,rs,re,val,2*pos+2,lazy);
	segment[pos]=(segment[2*pos+1]+segment[2*pos+2]);
    return;

}
int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
	ll n,q;
	cin>>n>>q;
	ll a[n]={0};
	ll k=4*n+1;
    ll lazy[k]={0};

	//int l=n;
	/*if(n&1)
	{
    while(l&n)
    {
    l++;
    }
	}*/

	ll segment[k]={0};

	construct_tree(a,segment,0,n-1,0);

	while(q--)
	{
	int num;
	cin>>num;
	if(num==1)
	{
	ll p,q;
	cin>>p>>q;
	cout<<range_sum_query(segment,p-1,q-1,0,n-1,0,lazy)<<endl;
	//print_tree(segment,k);
    //cout<<endl;
	}
	else
	{
	ll p,q,v;
	cin>>p>>q>>v;
	update_range_lazy(segment,0,n-1,p-1,q-1,v,0,lazy);
	//print_tree(segment,k);
    //cout<<endl;
	}
}
}
}
