
Debojyoti Sinha • a month ago • edited
Correct Answer.Correct Answer
Execution Time:0.22

class Solution
{
    public:
    string rearrangeString(string str)
    {
        int hash[26] = {0};
        
        for(int i = 0; i < str.size(); i++)
        {
            hash[str[i] - 'a']++;
        }
        
        priority_queue<pair<int, char="">> pq;
        
        for(int i = 0; i < 26; i++)
        {
            if(hash[i] != 0)
            {
                pq.push({hash[i], i + 'a'});
            }
        }
        
        string res;
        
        auto temp = pq.top();
        pq.pop();
        
        res = temp.second;
        temp.first -= 1;
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            
            res += top.second;
            
            if(temp.first > 0)
            {
                pq.push({temp.first, temp.second});
            }
            
            temp = {top.first - 1, top.second};
        }
        
        if(res.size() != str.size())
        {
            return "-1";
        }
        
        return res;
    }
};