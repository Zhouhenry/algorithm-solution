    #pragma comment(linker, "/STACK:65777216")

    #include <algorithm>
    #include <iostream>
    #include <string>
    #include<sstream>
    #include<string.h>
    #include <cstdio>
    #include <vector>
    #include <bitset>
    #include <cmath>
    #include <queue>
    #include<stack>
    #include <set>
    #include <map>
    #include<ctime>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int,int> pii;
    typedef pair<double,double> pdd;
    typedef unsigned long long ull;

    #define FOR(i,a,b) for (int i(a); i < (b); i++)
    #define REP(i,n) FOR(i,0,n)
    #define SORT(v) sort((v).begin(),(v).end())
    #define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
    #define CL(a,b) memset(a,b,sizeof(a))
    #define pb push_back

    string s;
    int a[33];
    int k;
    bool u[33];

    int main(){
    
            freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
    
            getline(cin,s);
            cin>>k;
            REP(i,s.size()) a[s[i]-'a']++;

            vector<pii> v;
            REP(i,26) v.pb(pii(a[i],i));
            SORT(v);
            int curr = 0;
            while(v.size() && curr + v[0].first<=k){
                    curr += v[0].first;
                    u[v[0].second] = true;
                    v.erase(v.begin());
            }
            cout<<v.size()<<endl;
            string t;
            REP(i,s.size()) if(!u[s[i]-'a']) t.pb(s[i]);
            printf("%s",t.c_str());

   
            cout<<endl<<endl<<"TIME: "<<clock()<<endl;

            return 0;
    }
