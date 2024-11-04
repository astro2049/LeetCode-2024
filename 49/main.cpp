#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<pair<string, int>> sis;
        for (int i = 0; i < strs.size(); i++) {
            auto s = strs[i];
            sort(s.begin(), s.end());
            sis.emplace_back(s, i);
        }

        sort(sis.begin(), sis.end());

        vector<vector<string>> anagramGroups;
        vector<string> anagrams = {strs[sis[0].second]};
        for (int i = 1; i < sis.size(); i++) {
            if (sis[i].first == sis[i - 1].first) {
                anagrams.push_back(strs[sis[i].second]);
            } else {
                anagramGroups.push_back(anagrams);
                anagrams = {strs[sis[i].second]};
            }
        }
        anagramGroups.push_back(anagrams);

        return anagramGroups;
    }
};
