#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> visited;
    vector<vector<int>> edges;
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        visited.resize(numCourses);
        edges.resize(numCourses);

        for (auto &prerequisite: prerequisites) {
            edges[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 2) {
                continue;
            }
            visited[i] = 1;
            if (!dfs(i)) {
                return {};
            }
            visited[i] = 2;
            res.push_back(i);
        }

        return res;
    }

    bool dfs(int i) {
        for (auto &next: edges[i]) {
            if (visited[next] == 2) {
                continue;
            } else if (visited[next] == 1) {
                return false;
            }
            visited[next] = 1;
            if (!dfs(next)) {
                return false;
            }
            visited[next] = 2;
            res.push_back(next);
        }

        return true;
    }
};
