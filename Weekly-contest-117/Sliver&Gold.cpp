/*
  There are N coins kept in a line. Each coin has two sides - one is colored gold and the other silver.
  You can flip two adjacent coins any number of times. You need to make the gold-colored side of every coin facing up.
  You are given the initial status of coins in a binary string s where '1' represents the gold side facing up and '0' represents the silver side facing up.
  If it is possible to make the gold-colored side of every coin facing up, return "Yes", otherwise return "No".

      Example 1: 
      
      Input:
      N = 8, s = "11001100"
      Output:
      Yes
      Explanation: 
      Flipping 3rd and 4th coin together and 7th 
      and 8th coin together will do the task.
*/

class Solution {
public:
    string flipCoins(int N, string s) {
        // Initialize a counter to keep track of the number of '0' flips
        int count = 0;
        
        // Iterate through each character (coin flip) in the input string
        for (auto it : s) {
            if (it == '0')
                count++; // Increment the counter if the flip is '0'
        }
        
        // Check if the number of '0' flips is even or odd
        // If even, return "Yes" indicating it's possible to have equal heads and tails
        // If odd, return "No" indicating it's not possible to have equal heads and tails
        if (count % 2 == 0)
            return "Yes";
        else
            return "No";
    }
};
