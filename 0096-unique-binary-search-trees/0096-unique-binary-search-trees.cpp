class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for(int i = 0; i<n; i++){
            ans *= n*2-i;
            ans/= i+1;
        }
        return ans/(n+1);
    }
};