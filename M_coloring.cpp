//https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273?leftPanelTab=0
//https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

bool isSafe(vector<vector<int>> graph, int c, vector<int> color, int v, int V){
    for(int i = 0; i<V; i++){
        if(graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool util(vector<vector<int>> graph, int m, vector<int> color, int v, int V){
    if(v == V)
        return true;
    for(int c = 1; c<=m; c++){
        if(isSafe(graph, c, color, v, V)){
            color[v] = c;
            if(util(graph, m, color, v+1, V))
                return true;
        }
        color[v] = 0;
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int V = mat.size();
    vector<int> color(V, 0);
    
    if(util(mat, m, color, 0, V))
        return "YES";
    return "NO";
}
