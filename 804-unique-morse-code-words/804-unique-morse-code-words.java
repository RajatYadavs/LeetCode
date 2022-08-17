class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        ArrayList<String>list=new ArrayList<>(Arrays.asList(".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."));
        
        HashSet<String>unique=new HashSet<String>();
        
        for(int i=0;i<words.length;i++){
            String t="";
            for(int j=0;j<words[i].length();j++){
                char c=words[i].charAt(j);
                int n=c-'a';
                t+=list.get(n);
            }
            unique.add(t);
        }
        return unique.size();
    }
}