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

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        visited.resize(numCourses);
        edges.resize(numCourses);

        for (auto &prerequisite: prerequisites) {
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            visited[i] = 1;
            if (!dfs(i)) {
                return false;
            }
            visited[i] = 2;
        }

        return true;
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
        }

        return true;
    }
};
