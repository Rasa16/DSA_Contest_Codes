//https://www.codingninjas.com/codestudio/problems/number-of-triangles-in-an-undirected-graph_920544?topList=top-graphs-interview-questions&leftPanelTab=0

int triangleInGraph(int graph[][100], int v) {
    // Write your code here.
    int count = 0;
    
    for(int i = 0; i<v; i++){
        for(int j = 0; j<v; j++){
            for(int k = 0; k<v; k++){
                if(graph[i][j] && graph[j][k] && graph[k][i])
                    count++;
            }
        }
    }
    return count/6;
}
