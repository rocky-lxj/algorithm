ll qsm(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1)ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}