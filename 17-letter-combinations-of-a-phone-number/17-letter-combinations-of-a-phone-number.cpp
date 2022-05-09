void Generate(int pos,string key,vector<string>&res,
              string digits,unordered_map<int,vector<char>>keypad)
{
    if(pos==digits.size())
    {
        res.push_back(key);
    }
    
    char c=digits[pos];
    
    for(int i=0;i<keypad[c].size();i++)
    {
        key+=keypad[c][i];
        Generate(pos+1,key,res,digits,keypad);
        key.pop_back();
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty())
            return res;
        unordered_map<int,vector<char>>keypad;
        
        keypad.insert(make_pair('2',vector<char>({'a','b','c'})));
        keypad.insert(make_pair('3',vector<char>({'d','e','f'})));
        keypad.insert(make_pair('4',vector<char>({'g','h','i'})));
        keypad.insert(make_pair('5',vector<char>({'j','k','l'})));
        keypad.insert(make_pair('6',vector<char>({'m','n','o'})));
        keypad.insert(make_pair('7',vector<char>({'p','q','r','s'})));
        keypad.insert(make_pair('8',vector<char>({'t','u','v'})));
        keypad.insert(make_pair('9',vector<char>({'w','x','y','z'})));
        
        string key="";
        Generate(0,key,res,digits,keypad);
        return res;
    }
};