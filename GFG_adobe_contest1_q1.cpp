class Solution
{

public:
static bool mycmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}
    int mindistinct(int Arr[], int N, int K)
    {
	    // code here
	    map<int, int> m;
	    for(int i = 0; i<N; i++){
	        m[Arr[i]]++;
	    }
	    
	    vector<pair<int, int>> v;
	    pair<int, int> p;
	    for(auto x:m){
	        p = {x.first, x.second};
	        v.push_back(p);
	    }
	    
	    sort(v.begin(), v.end(), mycmp);
	    
	    int i = 0;
	    //while(i != K){
	        for(int j = 0; j<v.size(); j++){
	            if(i + v[j].second <= K){
	                i += v[j].second;
	                v[j].second = 0;
	                if(i == K)
	                    break;
	            }
	            else{
	                v[j].second -= (K-i);
	                i = K;
	                break;
	            }
	        }
	    //}
	    int c = 0;
	    for(auto i:v){
	        if(i.second > 0)
	            c++;
	    }
	    return c;
    }
};