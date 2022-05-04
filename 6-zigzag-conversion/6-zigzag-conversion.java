class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        StringBuilder res = new StringBuilder();
        int skip = (numRows - 1) * 2;

        for(int start = 0; start < numRows; start++) {
            for(int i = start; i < s.length(); i += skip) {
                res.append(s.charAt(i));
                int newSkip = i + skip - (start * 2);
                if (start != 0 && newSkip < s.length() && i != newSkip) {
                   res.append(s.charAt(newSkip)); 
                }
            }
        }
        return res.toString();
    }
}