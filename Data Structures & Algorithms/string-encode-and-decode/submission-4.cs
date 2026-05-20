public class Solution {

    public string Encode(IList<string> strs) {
        string ans = "";
        
        for(int i = 0; i < strs.Count(); i++)
        {
            if(strs[i] == ""){ans += "~-";}
            else{
                ans += $"{strs[i]}-";
            }
        }
        return ans;
    }

    public List<string> Decode(string s) {
        List<string> strs = s.Split('-').ToList()
        .Where(s => s != "").ToList();

        for(int i = 0; i < strs.Count(); i++)
        {
            if(strs[i] == "~")
            {
                strs[i] = "";
            }
        }
        return strs;
   }
}
