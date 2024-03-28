#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        map<int,int> InterMap;
        set<int> Union;
        for(int i = 0; i < n; i++)
        {
            int x; 	cin>>x;
            InterMap[x] = 1;
            Union.insert(x);
        }
        for(int i = 0; i < m; i++)
        {
            int x; 	cin>>x;
            InterMap[x]++;
            Union.insert(x);
        }
        for(auto x : Union)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x : InterMap)
        {
            if (x.second >= 2)
            {
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
}