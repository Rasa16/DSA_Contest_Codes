//https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376558?leftPanelTab=0

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    vector<int> t;
    for(int i = 0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1])
            continue;
        int x = arr[i];
        int j = i+1, k = n-1;
        while(j < k){
            if(x+arr[j]+arr[k] == K){
                t.push_back(x);
                t.push_back(arr[j]);
                t.push_back(arr[k]);
                res.push_back(t);
                t.clear();
                while(j < n-1 && arr[j] == arr[j+1])
                    j++;
                while(k>0 && arr[k] == arr[k-1])
                    k--;
                j++;
                k--;
            }
            else if(x+arr[j]+arr[k] < K)
                j++;
            else
                k--;
        }
    }
    return res;
}
