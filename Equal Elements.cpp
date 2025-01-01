class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort the array to align all elements around the median
        sort(nums.begin(), nums.end());
        
        // Use two pointers to calculate the total number of moves
        int s = 0;                      // Start pointer
        int e = nums.size() - 1;        // End pointer
        int count = 0;                  // Counter for total moves
        
        // Move both pointers towards the center
        while (s < e) {
            // Add the difference between the elements at start and end
            count += abs(nums[s] - nums[e]);
            s++;                        // Move start pointer forward
            e--;                        // Move end pointer backward
        }
        
        // Return the total number of moves to make all elements equal
        return count;
    }
};
