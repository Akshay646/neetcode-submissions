class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while(start <= end)
        {
            //if both are alphnumeric
            if(isalnum(s[start]) &&  isalnum(s[end]))
            {
                //see if they are equal
                if(tolower((unsigned char)s[start]) 
                != tolower((unsigned char)s[end]))
                {
                    return false;
                }
                start++; end--;
            }
            else if(!isalnum(s[start]))
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return true;
    }
};
