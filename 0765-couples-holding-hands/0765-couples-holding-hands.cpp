class Solution {
public:
    int minSwapsCouples(vector<int>& row){
        map<int,int> a;
        for(int i=0;i<row.size()-1;){
            a[i]=i+1;
            a[i+1]=i;
            i=i+2;
        }
        int s=0;
     vector<bool> dp(row.size(),false);
    for(int i=0;i<row.size()-1;i++){
        if(dp[i]==true)continue;
        if(row[i+1]==a[row[i]]){
            dp[i]=true;
            dp[i+1]=true;
        }else{
            s+=1;
            for(int j=i+1;j<row.size();j++){
                if(row[j]==a[row[i]]){
                    row[j]=row[i+1];
                    row[i+1]=a[row[i]];
                    dp[i]=true;
                    dp[i+1]=true;
                    break;
                }
            }
        }
      }
        return s;
    }
};