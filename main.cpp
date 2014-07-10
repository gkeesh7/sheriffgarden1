#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;
#define FOR(i,a)    for(int i = 0;i < a;i++)
#define REP(i,a,b)  for(int i = a;i < b;i++)
#define vi vector<int>
#define MOD 1000000007
int main()
{
 set<long long int>s;/*to store unique cycle length*/
 vector<long long> v;
 long long ar[100001];/*input array by the user*/
 long long n,t,cyclen,rem;/*number of numbers, testcases, maximum ,current position , cycle length , remembered position*/
 long long int unvis(bool all[100001],long long int  k,long long n);
 long long int q;
 bool tr[100001];
 long long gcd(long long a, long long b);
 long long lcm,hcf;
 scanf("%lld",&t);
 while(t--)
 {
  s.clear();
  v.clear();
  memset(tr,false,sizeof(tr));
  scanf("%lld",&n);
  FOR(i,n)
  {
   scanf("%lld",&ar[i]);
  }
  q=0;
  while(q!=-1)
  {
   rem=q;
   cyclen=0;
   do
   {
    tr[q]=true;
    q=ar[q]-1;
    cyclen++;
   }
   while(rem!=q);
   s.insert(cyclen);
   q=unvis(tr,rem,n);
  }
  set<long long int>::iterator sit1;
  hcf=*(s.begin());
  lcm=1;
  for(set<long long int>::iterator sit=s.begin();sit!=s.end();++sit)
  {
   sit1=sit;
   if(++sit1!=s.end())
   {
   	hcf=gcd(hcf,*sit1);
   	if(hcf==1)
   	{
   	 break;
   	}
   }
  }
  if(hcf!=1&&s.size()!=1)
  {
   for(set<long long int>::iterator sit=s.begin();sit!=s.end();++sit)
   {
   	v.push_back(*(sit)/hcf);
   }
  }
  else
  {
   for(set<long long int>::iterator sit=s.begin();sit!=s.end();++sit)
   {
   	v.push_back(*(sit));
   }
  }
  for(vector<long long int>::iterator vit=v.begin();vit!=v.end();++vit)
  {
   lcm*=(*vit);
   if(lcm>MOD)
   {
   	lcm=lcm%MOD;
   }
  }
  printf("%lld\n",lcm);
 }
 return 0;
}
long long gcd(long long a, long long b)
{
 if(a==0)
 {
  return b;
 }
 else if(b==0)
 {
  return a;
 }
 else
 {
  if(a>=b)
  {
  	return gcd(b,a%b);
  }
  else
  {
    return gcd(a,b%a);
  }
 }
}
long long unvis(bool all[100001],long long k,long long n)
{
 REP(i,k,n)
 {
  if(all[i]==false)
  {
   return i;
  }
 }
 return -1;
}
