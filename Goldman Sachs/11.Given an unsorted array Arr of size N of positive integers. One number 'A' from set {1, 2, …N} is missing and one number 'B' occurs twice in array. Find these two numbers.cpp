// Question Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{

private:
    int findFirstSetBit(int num) {
        int i=0;
        while((num&1)!=1) {
            num = num>>1;
            i++;
        }
        return i;
    }
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        int xorAll=0,xorArr=0;
        for(int i=0; i<n; i++) {
            xorAll ^= i+1;
            xorArr ^= arr[i];
        }
        int xorOfTwoElems = xorAll ^ xorArr;
        int firstDifferentBit = findFirstSetBit(xorOfTwoElems);
        int bucketAll0 = 0, bucketAll1 = 0;
        int bucketArr0 = 0, bucketArr1 = 0;
        for(int i=0; i<n; i++) {
            if( ((arr[i])&(1<<firstDifferentBit)) != 0) {
                bucketArr1 ^= arr[i];
            } else {
                bucketArr0 ^= arr[i];
            }
            if( ((i+1)&(1<<firstDifferentBit)) != 0) {
                bucketAll1 ^= i+1;
            } else {
                bucketAll0 ^= i+1;
            }
        } 
        ans[0] = bucketArr0 ^ bucketAll0;
        ans[1] = bucketArr1 ^ bucketAll1;
        bool found = false;
        for(int i=0; i<n; i++) {
            if(arr[i]==ans[0]) {
                found = true;
                break;
            }
        }
        if(!found) swap(ans[0],ans[1]);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
