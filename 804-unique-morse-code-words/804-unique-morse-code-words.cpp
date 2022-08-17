class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>encode{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>unique;
        
        for(int i=0;i<words.size();i++){
            string t="";
            for(int j=0;j<words[i].size();j++){
                int n=words[i][j]-'a';
                t+=encode[n];
            }
            unique.insert(t);
        }
        return unique.size();
    }
};