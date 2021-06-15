class Solution {
public:
    static bool mycmp(pair<string, pair<int, int>> p1, pair<string, pair<int, int>> p2){
        if(p1.second.first == p2.second.first)
            return p1.second.second < p2.second.second;
        return p1.second.first < p2.second.first;
    }
    string arrangeWords(string text) {
        vector<pair<string, pair<int, int>>> v;
        
        int i = 0, j = 1, n = text.size();
        string t;
        pair<int, int> p;
        pair<string, pair<int, int>> q;
            while(j < n){
            if(text[j] == ' '){
                t = text.substr(i, j-i);
                p = {j-i, i};
                q = {t, p};
                v.push_back(q);
                
                j++;
                i = j;
            }
            j++;
        }
        if(j == n){
            t = text.substr(i, j-i);
                p = {j-i, i};
                q = {t, p};
                v.push_back(q);
        }
        sort(v.begin(), v.end(), mycmp);
        t = "";
        cout<<v.size();
        for(int i = 0; i<v.size()-1; i++){
            if(v[i].second.second == 0){
                v[i].first[0] = (v[i].first[0]-'A') + 'a';
            }
            if(i == 0){
                t = v[i].first;
                t[0] = (t[0]-'a') + 'A';
            }
            else
                t += v[i].first;
            t.push_back(' ');
        }
        if(v[v.size()-1].second.second == 0){
            v[v.size()-1].first[0] = (v[v.size()-1].first[0]-'A') + 'a';
        }
        t += v[v.size()-1].first;
        return t;
    }
};