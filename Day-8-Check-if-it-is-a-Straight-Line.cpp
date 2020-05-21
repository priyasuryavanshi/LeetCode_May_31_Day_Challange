/*

 Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.


*/

//URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int size = coordinates.size();
      if(size==1 || size==2) return true;
      float ratio = (float)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
     // cout<<ratio<<endl;
      float temp;
      for(int i=2; i<size; i++) {
        temp = (float)(coordinates[i][1]-coordinates[0][1])/(coordinates[i][0]-coordinates[0][0]);
        if(ratio !=temp) return false;
      }
      return true;
        
    }
};