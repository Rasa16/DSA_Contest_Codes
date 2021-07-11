//https://leetcode.com/problems/word-ladder/
//https://www.codingninjas.com/codestudio/problems/word-ladder_1102319?leftPanelTab=0

#include<bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict) 
{
	// Write your code here
    unordered_set<string> col(dict.begin(), dict.end());
    if(col.find(end) == col.end())
        return -1;
    queue<string> q;
    q.push(begin);
    int ans = 0;
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string t = q.front();
            q.pop();
            if(t == end)
                return ans+1;
            for(int i = 0; i<t.size(); i++){
                string word = t;
                for(char l = 'a'; l<= 'z'; l++){
                    word[i] = l;

                    if(col.find(word) != col.end() && word != t){
                        q.push(word);
                        col.erase(word);
                    }
                }
            }
        }
        ans++;
    }
    return -1;
}
