#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string connected;
        for (auto &s: strs) {
            string sLen = to_string(s.length());
            int o = sLen.length();
            for (int i = 0; i < 4 - o; i++) {
                connected += '0';
            }
            connected += sLen;
            connected += s;
        }

        return connected;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int len = stoi(s.substr(i, 4));
            i += 4;
            string subS = s.substr(i, len);
            i += len;
            strs.push_back(subS);
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
