class Solution
{
public:
    static bool mycomp(string a, string b)
    {
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> snums;
        for (auto n : nums)
        {
            snums.push_back(to_string(n));
        }

        sort(snums.begin(), snums.end(), mycomp);

        if (snums[0] == "0")
            return "0";
        // mycomp is a custom comparator which can be used to modify the sort    order from asc to desc
        string ans = "";

        // not required since we are using custom comparator
        //  for(int i=snums.size() -1; i>=0 ; i--){
        //      ans+=snums[i];
        //  }

        for (auto str : snums)
        {
            ans += str;
        }
        return ans;
    }
};
