#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define val 1000000001
#define debug(x) cout<< #x <<"="<<x<<endl
#define in(x) cin>>x
#define all(x) x.begin(),x.end()
#define PI 3.1415926535897932384626
#define profit first
#define deadline second

long long int power();long long int powermod();

void topological(map<int,vector<int>>& graph)
{
	map<int,int> m;
	set<int> nv;
	for(auto i:graph)
    {
		for(int j=0;j<i.second.size();j++)
		{
		    m[i.second[j]]++;
		    nv.insert(i.second[j]);
		}
		nv.insert(i.first);
	}

	queue<int> q;
	for(auto i:nv)
    {
        if(!m[i])
        {
            q.push(i);
        }
    }

	vector<int> ar;
	while(!q.empty())
    {
        ar.push_back(q.front());
		q.pop();
		for(int i=0;i<graph[ar.back()].size();i++)
        {
            m[graph[ar.back()][i]]--;
            if(!m[graph[ar.back()][i]])
            {
                q.push(graph[ar.back()][i]);
            }
        }
	}
	for (int i=0;i<ar.size();i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
}

void solution()
{
    long long int n;
    cin>>n;
    map<int,vector<int>> graph;
    for(int i=0;i<n;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        graph[node1].push_back(node2);

    }
    topological(graph);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;

    while(t--)
    {
        solution();
    }
    return 0;
}

long long int power(long long int a,long long int n)
{
    long long int pow=1;
    for(long long int i=n;i>0;i>>=1)
    {
        if(i&1)
        {
            pow*=a;
        }
        a*=a;
        //a>>=1;
    }
    return pow;
}

long long int powermod(long long int a,long long int n,long long int m)
{
    long long int pow=1;
    a%=m;
    for(long long int i=n;i>0;i>>=1)
    {
        if(i&1)
        {
            pow=pow*a%m;
        }
        a=a*a%m;
    }
    return pow;
}
