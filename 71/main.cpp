#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;
        for (int i = 0; i < path.size();) {
            if (path[i] == '/') {
                i++;
                continue;
            } else {
                int j = i + 1;
                for (; j < path.size() && path[j] != '/'; j++) {

                }
                int len = j - i;
                string word = path.substr(i, len);
                if (len == 1 && word == ".") {

                } else if (len == 2 && word == "..") {
                    if (!dirs.empty()) {
                        dirs.pop();
                    }
                } else {
                    dirs.push(std::move(word));
                }
                i = j;
            }
        }

        if (dirs.empty()) {
            return "/";
        }

        vector<string> vDirs(dirs.size());
        for (int i = vDirs.size() - 1; i >= 0; i--) {
            vDirs[i] = std::move(dirs.top());
            dirs.pop();
        }
        string simpPath;
        for (const auto &s: vDirs) {
            simpPath += "/" + s;
        }

        return simpPath;
    }
};
