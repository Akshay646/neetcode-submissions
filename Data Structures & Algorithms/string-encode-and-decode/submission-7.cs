public class Solution {

    public string Encode(IList<string> strs) {
        string ans = "";
        //We encode string as {Frequency+#+string; 4#neet}
        //because, after every first hash, we get the actual string
        foreach(string s in strs)
        {
            ans += (s.Length.ToString()) + '#' + s;
        }
        //Console.WriteLine(ans);
        return ans;
    }

    public List<string> Decode(string s) {
        //4444#neetcodeloveyou
        List<string> res = new List<string>();

        int i = 0, j = 0;
        while(i < s.Length)
        {
            j = i;
            //increment j until you come across '#'
            //After hash, you will have actuall string
            while(s[j] != '#'){j++;}

            //Get the lenght, we get substring from i to j - 1
            //becoz, if we just do j - 1, then it works if lenght
            //is of one digit, otherwise fails
            int length = int.Parse(s.Substring(i, j - i));

            //now get the string from j + 1, until len no. of chars
            string tmp = s.Substring(j + 1, length);
            res.Add(tmp);
            //Now your i will point to char which is at
            //j + length + 1 position. i.e length chars away from j

            i = j + length + 1;
        }

        return res;
   }
}
