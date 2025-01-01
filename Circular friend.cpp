class Solution {
public:
    // Helper function to find the winner's index using recursion
    // This is based on the Josephus Problem:
    // - If there's only one person left (n == 1), they are the winner (index 0).
    // - For more than one person, the winner's position is determined by the 
    //   position of the winner in the smaller group (n-1) adjusted with k (steps).
    int winner_idx(int n, int k) {
        if (n == 1) {
            return 0; // Base case: Only one person remains, they are the winner
        }
        // Recursive relation: The winner's index shifts as we add k steps in a circular fashion
        int ans = (winner_idx(n - 1, k) + k) % n;
        return ans;
    }

    // Main function to find the winner (1-based index)
    int findTheWinner(int n, int k) {
        int ans = winner_idx(n, k); // Find the winner's index (0-based)
        return ans + 1; // Convert to 1-based indexing for the answer
    }
};
