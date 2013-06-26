#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#include <list>
#include <vector>
using namespace std;

#define forn(i,n) for(long long i=0;i<n;++i)
#define forx(i,n) for(long long i=n;i>=1;--i)
#define forab(i,a,b) for (long long i=b;i>=a;--i)
template <class T> T gcd(T a, T b);
long long mod(long long a,long long d,long long n);
bool isPrime(long long a);
bool isPrimeMB(long long n,int round);

bool check(long long a);

int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	long long num;
    forab(a,1,9)
    forab(b,0,9)
    forab(c,0,9)
    {
        num =a*100000+a;
        num+=b*10000 +10*b;
        num+=c*1000  +c*100;
        if(check(num))
        {
            cout<<num<<endl;
            int i;
            for(i=100;i<=999;i++)
            if(num%i==0)
                cout<<i<<" "<<num/i<<endl;
            return 0;
        }
        
    }
}
bool check(long long n)
{
    for(int i=100;i<=999;i++)
    {
        if(n%i==0)
        {
            int t=n/i;
            if(100<=t && t<=999) return true;
        }
    }
    return false;
}
template <class T> //t:int, long
T gcd(T a, T b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	T c;
	while(b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}
long long mod(long long a,long long d,long long n) //a^d mod n
{
	if(d==0) return 1;
	long long tmp =mod(a,d/2,n);
	long long rs= tmp*tmp%n;
	if(d%2==1) rs=rs*a %n;
	return rs;
}
bool isPrime(long long a){ //thong thuong
	long lim=sqrt(a);
	if(a<=1) return false;
	if(a==2) return true;
	if(a%2==0) return false;
	long i;
	for(i=3;i<=lim;i=i+2){
		if(a%i==0) return false;
	}
	return true;
}
bool isPrimeMB(long long n,int round){ //Phep thu Miller-Rabin voi round vong , n le , lon hon 3
	int s;
	long long d,a,x;

	d=n-1;
	s=0;
	while(d%2==0){
		s++;
		d/=2;
	}
	//n-1 = 2^s .d
	srand ( time(NULL) );
	forx(i,round){
		a=rand()%(n-3)+2;
		x= mod(a,d,n);
		if(x==1 || x==n-1) continue;
		bool found=false;
		forx(r,s-1)
		{
			x=(x*x)%n;
			if(x==1) return false;
			if(x==n-1){
				found=true;
				break;
			}
		}
		if(!found) return false;
	}
	return true;
}


