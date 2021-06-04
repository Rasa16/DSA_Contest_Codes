class Solution {
public:
    int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int hd = INT_MIN;
        int vd = INT_MIN;
        bool vf = 0, hf = 0;
        if(horizontalCuts.size() == 1){
            hd = max((horizontalCuts[0]-0), (h - horizontalCuts[0]));
            hf = 1;
        }
        if(verticalCuts.size() == 1){
            vd = max((verticalCuts[0]-0), (w - verticalCuts[0]));
            vf = 1;
        }
        
        if(!hf){
            hd = horizontalCuts[0]-0;
            for(int i = 0; i<horizontalCuts.size()-1; i++)
                hd = max(hd, horizontalCuts[i+1]-horizontalCuts[i]);
            hd = max(hd, h - horizontalCuts[horizontalCuts.size()-1]);
        }    
        if(!vf){
            vd = verticalCuts[0]-0;
            for(int i = 0; i<verticalCuts.size()-1; i++)
                vd = max(vd, verticalCuts[i+1]-verticalCuts[i]);
            vd = max(vd, w - verticalCuts[verticalCuts.size()-1]);
        }   
        return (long)((long)(hd%mod)*(long)(vd%mod))%mod;
    }
};