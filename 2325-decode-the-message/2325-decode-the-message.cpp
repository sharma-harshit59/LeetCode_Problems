class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> cipher;
        char ch = 'a';
        for (int i = 0; i < key.size(); i++)
            if (!cipher.count(key[i]) && key[i] != ' ')
                cipher[key[i]] = ch++;
        cipher[' '] = ' ';
        string msg = "";
        for (int i = 0; i < message.size(); i++)
            msg += cipher[message[i]];
        return msg;
    }
};