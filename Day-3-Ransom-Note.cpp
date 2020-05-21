/*

 Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.

*/

//URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char,int> mmap;
        
        for(int i=0; i<magazine.size(); i++) {
            if(mmap.find(magazine[i]) == mmap.end()) {
                mmap[magazine[i]] = 1;
            }
            else {
                mmap[magazine[i]] +=1; }
        }
            
        for(int i=0; i < ransomNote.size(); i++) {
            if(mmap.find(ransomNote[i])==mmap.end()) {
                return false;
            }
            else {
                if(mmap[ransomNote[i]] <= 0) {
                    return false;
                }
                else {
                    mmap[ransomNote[i]] -=1;
                }
            }
        }
            
        return true;
        
    }
};