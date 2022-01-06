Question Link: https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/#

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        return (K+M-1)%N == 0 ? N : (K+M-1)%N;
    }
};