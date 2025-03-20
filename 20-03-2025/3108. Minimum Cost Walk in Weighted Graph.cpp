class Solution {
public:
void dfs(int node, int component, unordered_map<int, vector<pair<int, int>>>& graph, 
             vector<int>& visited, unordered_map<int, int>& minAnd) {
        visited[node] = component;  
        for (auto& [neighbor, weight] : graph[node]) {
            minAnd[component] &= weight;  
            if (visited[neighbor] == -1) { 
                dfs(neighbor, component, graph, visited, minAnd);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, vector<pair<int, int>>> graph;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> visited(n, -1); 
        unordered_map<int, int> minAnd;
        int component = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) { 
                minAnd[component] = INT_MAX;
                dfs(i, component, graph, visited, minAnd);
                component++;
            }
        }

        vector<int> result;
        for (auto& query : queries) {
            int si = query[0], ti = query[1];
            if (visited[si] != visited[ti]) {
                result.push_back(-1); 
            } else {
                result.push_back(minAnd[visited[si]]);
            }
        }
        
        return result;
    }
};
