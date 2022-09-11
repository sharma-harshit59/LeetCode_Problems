class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        
        int n = needle.size(), h = haystack.size();
        if (n > h)
            return -1;
        
        if (n == h)
            return (needle == haystack) ? 0 : -1;
        
        int i = 0;
        while (i <= h - n) {
            if (needle == haystack.substr(i, n))
                return i;
            i++;
        }
        return -1;
    }
};