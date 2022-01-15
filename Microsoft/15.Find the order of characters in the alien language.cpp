// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(vector<int> adj[],int src,stack<int>& st,vector<bool> & visited)
    {
        visited[src]=true;
        for(auto it:adj[src])
        {
            if(!visited[it])
            {
                dfs(adj,it,st,visited);
            }
        }
        st.push(src);
    }
    string findOrder(string dict[], int n, int k) {
        //code here
                vector<int> adj[26];
        int i,j;
        for(i = 0; i <= n-2; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            for(j = 0; j < min(word1.size(), word2.size());j++)
            {
                if(word1[j] != word2[j])
                {
                    int index1 = word1[j] - 'a';
                    int index2 = word2[j] - 'a';
                    
                    adj[index1].push_back(index2);
                    
                    break;
                }
            }
        }
        vector<bool> visited(26,false);
        stack<int> st;
        for(i=0;i<=25;i++)
        {
            if(!visited[i] && adj[i].size()>0)
            {
                dfs(adj,i,st,visited);
            }
            // for(auto it:adj[i])
            // {
            //     if(!visited)
            // }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top()+'a';
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
