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

void showGraphMatrix(map<int,map<int,long>> &graph) {
    for (auto i=graph.begin(); i!=graph.end(); i++) {
        cout << i->first << ": ";
        for (auto j=i->second.begin(); j!=i->second.end(); j++) {
            cout << "[" << j->first << " time " << j->second << "],"; 
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<long> visited;
    priority_queue<pair<long long,long>, vector<pair<long long,long>>, greater<pair<long long,long>>> queue;
    map<int,map<int,long>> graph;
    vector<long long> lowest(n, -1);
    lowest[0] = 0;

    long a, b;
    long long c;
    while (m--) {
        cin >> a >> b >> c;
        if ((graph[a].contains(b) && graph[a][b] > c) || !(graph[a].contains(b))) {
            graph[a][b] = c;
        }
    }

    // showGraphMatrix(graph);

    queue.push({0,1});
    // cout << "pq top: " << queue.top().second << endl;
    while (queue.size()) {
        // cout << "queue top: " << queue.top().second << endl;
        // cout << "lowest: ";
        // for (auto i=lowest.begin(); i!=lowest.end(); i++) cout << *i << ' '; cout << endl;

        visited.insert(queue.top().second);

        if (!graph.contains(queue.top().second)) {
            if (queue.size() > 1) {
                queue.pop();
            }
            else {
                break;
            }
            continue;
        }

        for (auto i=graph[queue.top().second].begin(); i!=graph[queue.top().second].end(); i++) {
            if ((lowest[queue.top().second-1]+(i->second)) < lowest[(i->first)-1] || lowest[(i->first)-1] == -1) {
                lowest[(i->first)-1] = lowest[queue.top().second-1]+(i->second);
                if (visited.find(i->first) == visited.end()) {
                    queue.push({lowest[(i->first)-1],i->first});
                    visited.insert(i->first);
                }
            }
        }
        if (queue.size() > 1) {
            queue.pop();
        }
        else {
            break;
        }

        // cout << "<->     ";
        // for (auto i=lowest.begin(); i!=lowest.end(); i++) cout << *i << ' '; cout << endl;
    }

    for (int i=0; i<n; i++) cout << lowest[i] << (i==(n-1) ? endl : ' ');
 
    return 0;
}
