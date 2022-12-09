1-https://leetcode.com/problems/stone-game


class Solution {
public:
int dp[505][505][2];
    int cal(int l,int r,int turn,vector<int>& piles){
        if(l>r)
        return 0;

        if(dp[l][r][turn]!=-1)
        return dp[l][r][turn];

        if(turn){
            return dp[l][r][turn]=max(piles[l]+cal(l+1,r,0,piles),piles[r]+cal(l,r-1,0,piles));
        }else{

           return dp[l][r][turn]=min(cal(l+1,r,1,piles),cal(l,r-1,1,piles)); 
        }
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        int total=cal(0,n-1,1,piles);
        int s=0;
        for(auto i:piles)
        s+i;

        if(s-total<=total)
        return 1;
        else
        return 0;
    }
};
