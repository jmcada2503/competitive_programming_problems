#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>

#define endl '\n'

using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    vector<vector<pair<int,int>>> connections = vector<vector<pair<int,int>>>(vertices, vector<pair<int,int>>());
    for (int i=0; i<edges; i++) {
        connections[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        connections[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }

    vector<int> ans = vector<int>(vertices, -1);
    ans[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> queue;
    queue.push({0, source});

    while (queue.size()) {
        pair<int,int> check = queue.top();
        for (int i=0; i<connections[check.second].size(); i++) {
            if ((ans[check.second]+connections[check.second][i].second) < ans[connections[check.second][i].first] || ans[connections[check.second][i].first] == -1) {
                ans[connections[check.second][i].first] = ans[check.second]+connections[check.second][i].second;
                queue.push({ans[connections[check.second][i].first], connections[check.second][i].first});
            }
        }
        if (queue.size() > 1) {
            queue.pop();
        }
        else {
            queue = *(new priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>());
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int vertices, edges, source;
    cin >> vertices >> edges >> source;

    vector<vector<int>> edge = vector<vector<int>>(edges, vector<int>(3, 0));
    for (int i=0; i<edges; i++) {
        cin >> edge[i][0];
        cin >> edge[i][1];
        cin >> edge[i][2];
    }

    for (int i=0; i<edges; i++) {
        for (int j=0; j<3; j++) {
            cout << edge[i][j] << ' ';
        }
        cout << endl;
    }

    vector<int> ans = dijkstra(edge, vertices, edges, source);

    cout << "ans:" << endl;
    for (auto i : ans) cout << i << ' '; cout << endl;

    return 0;
}
