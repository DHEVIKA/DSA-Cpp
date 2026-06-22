class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        vector<int>temp(26,0);
        for(int i=0;i<text.size();i++)
        {
            temp[text[i]-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++)
        {
            if(i==0 || i==1 || i==13)
            {
                ans = min(ans,temp[i]);
            }
            else if(i==11 || i==14)
            {
                int t = temp[i]/2;
                ans = min(ans,t);
            }
        }
        return ans;
    }

};