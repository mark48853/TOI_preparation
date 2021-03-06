#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
map<int,int> mp; /// pos : val
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,op; cin >> n >> k >> op; k = LONG_MAX;
    queue<pair<pii,int> > q;     /// day : val :: pos
    q.push({{1,0},op});
    int d = 0,mx=0;
    int bookpos,bookval;
    while(!q.empty())
    {
        ll day = q.front().f.f;
        ll val = q.front().f.s;
        ll pos = q.front().s;
        q.pop();
        if(mp[pos]!=NULL and mp[pos] > val ) continue;
        mp[pos] = val;
        if(day == n+1) {mx=val;break;}
        if(day >  d  ) {cin >> bookpos >> bookval; d++;}
        if(pos+k >= bookpos and pos < bookpos) q.push({{day+1,val+bookval},bookpos});
        if(pos-k <= bookpos and pos > bookpos) q.push({{day+1,val+bookval},bookpos});
        if(pos == bookpos) q.push({{day+1,val+bookval},bookpos});
        q.push({{day+1,val},pos});
    }
    while(!q.empty())
    {
        int t = q.front().f.s;
        q.pop();
        mx = max(mx,t);
    }
    cout << mx;
}
