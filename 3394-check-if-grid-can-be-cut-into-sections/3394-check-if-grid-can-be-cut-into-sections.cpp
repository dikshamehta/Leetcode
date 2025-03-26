class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal(0) and vertical cuts(1)
        // similar to merge intervals
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 // if dim = 0 -> a[0] < b[0] (sort based on startx)
                 // if dim = 1 -> a[1] < b[1] (sort based on starty)
                 return a[dim] < b[dim];
             });

        // Saving the ending of the first element after sorting based on start
        // if horizontal (0) -> rectangles[0][2] (endx)
        // if horizontal (1) -> rectangles[0][3] (endy)
        int furthestEnd = rectangles[0][dim + 2]; 

        for (size_t i = 1; i < rectangles.size(); i++) {
            //vector<int>& rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rectangles[i][dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rectangles[i][dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }
};