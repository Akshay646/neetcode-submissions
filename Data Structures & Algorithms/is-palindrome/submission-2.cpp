class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while(start < end)
        {
            //keep both while loops alive until you actually
            //land on alphanumeric char on both the ends
            while(start < end && !isalnum((unsigned char)s[start]))
            {
                start++;
            }

            while(start < end && !isalnum((unsigned char)s[end]))
            {
                end--;
            }
                //see if they are equal
            if(tolower((unsigned char)s[start]) 
            != tolower((unsigned char)s[end]))
            {
                    return false;
            }
            start++; end--;
        }

        return true;
    }
};
