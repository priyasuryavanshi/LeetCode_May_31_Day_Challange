/*

 First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters. 

*/

//URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        vector <int> list(26,0);
      
        for(int i=0; i<size; i++) {
          list[s[i]-'a'] +=1;
        }
      
        for(int i=0; i<size; i++) {
           if(list[s[i]-'a'] == 1) {
             return i;
           }
        }
        return -1;
    }
};