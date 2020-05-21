/*

 Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1

*/

//URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

class Solution {
public:
    bool isPerfectSquare(int num) {
      int x=1;
      while(num>=0) {
        num-=x;
        if(num==0) {
          return true;
        }
        x+=2;
      }
      return false;
    }
};