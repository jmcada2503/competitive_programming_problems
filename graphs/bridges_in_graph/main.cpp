#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>

#define endl '\n'

using namespace std;

int actual_position = 1;

void bridges(
        vector<vector<int>> &nodes,
        vector<int> &position,
        vector<int> &lower,
        vector<vector<int>> &bridge,
        int parent = NULL,
        int node = 0
        ) {

    position[node] = actual_position;
    lower[node] = actual_position;
    for (int i=0; i<nodes[node].size(); i++) {
        if (nodes[node][i] != parent && position[nodes[node][i]] == 0) {
            actual_position++;
            bridges(nodes, position, lower, bridge, node, nodes[node][i]);
        }
    }

    for (int i=0; i<nodes[node].size(); i++) {
        if (nodes[node][i] != parent && (lower[nodes[node][i]] && lower[nodes[node][i]] < lower[node])) {
            lower[node] = lower[nodes[node][i]];
        }
    }

    if (lower[node] > position[parent]) {
        vector<int> b{node, parent};
        bridge.push_back(b);
    }


}

class Solution {
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

            vector<int> position = vector<int>(n,0);
            vector<int> lower = vector<int>(n,0);
            vector<vector<int>> bridge;
            vector<vector<int>> con = vector<vector<int>>(n, vector<int>(0));

            for (int i=0; i<connections.size(); i++) {
                con[connections[i][0]].push_back(connections[i][1]);
                con[connections[i][1]].push_back(connections[i][0]);
            }

            bridges(con, position, lower, bridge);

            return bridge;
        }
};

int main() {
    Solution solution;
    vector<vector<int>> x{{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}};
    vector<vector<int>> ans;
    ans = solution.criticalConnections(6, x);

    cout << endl << "bridges:" << endl;
    for (int i=0; i<ans.size(); i++) cout << ans[i][0] << " <-/-> " << ans[i][1] << endl;

    return 0;
}
