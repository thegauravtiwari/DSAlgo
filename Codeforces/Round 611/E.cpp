    
#include <bits/stdc++.h>
#define pb      push_back
#define fastIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define PI      3.141592653589793238462643383
#define mp      make_pair
#define ff      first
#define ss      second
#define endl    "\n"
#define all(v)  v.begin(),v.end()
#define int     long long

using namespace std;
typedef pair<int,int> pii;
typedef pair<long double,long double>pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T> >;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
        if(n > 0)
            s << arr[n - 1] ;
        s<< "]";
        return s.str();
    }
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif

    fastIO;
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    set<int> s;
    a[1]++;
    s.insert(a[1]);
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<=1)
        {
            a[i]=a[i-1];
        }
        else
        {
            a[i]++;
        }
        s.insert(a[i]);
    }
    cout<<s.size()<<" ";
    s.clear();
    b[1]--;
    s.insert(b[1]);
    for(int i=2;i<=n;i++)
    {
        if(b[i]-b[i-1]>1)
        {
            b[i]--;
        }
        else if(b[i]==b[i-1])
        {
            b[i]++;
        }
        else if(b[i]==b[i-1]-1) 
        {
            b[i]=b[i-1];
        }
        s.insert(b[i]);
    }
    cout<<s.size();
    
    
    return 0;
}
