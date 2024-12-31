class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // Step 1: Translate the rectangle and circle so that the circle is centered at the origin
        // This simplifies the calculations.
        x1 -= x_center; // Shift the rectangle's bottom-left x-coordinate relative to the circle's center
        x2 -= x_center; // Shift the rectangle's top-right x-coordinate relative to the circle's center
        y1 -= y_center; // Shift the rectangle's bottom-left y-coordinate relative to the circle's center
        y2 -= y_center; // Shift the rectangle's top-right y-coordinate relative to the circle's center

        // Step 2: Find the minimum distance squared between the circle's center (now at origin) 
        // and the rectangle along both x and y axes.
        // If the rectangle lies completely on one side of the origin along the x-axis, 
        // calculate the closest x-coordinate squared distance. Otherwise, the closest point
        // along the x-axis is 0 (directly aligned with the origin).
        int minX = x1 * x2 > 0 ? min(x1 * x1, x2 * x2) : 0;

        // Similarly, find the closest y-coordinate squared distance.
        // If the rectangle lies completely above or below the origin along the y-axis,
        // calculate the closest y-coordinate squared distance. Otherwise, the closest point
        // along the y-axis is 0.
        int minY = y1 * y2 > 0 ? min(y1 * y1, y2 * y2) : 0;

        // Step 3: Compare the sum of the minimum squared distances (minX + minY)
        // to the square of the circle's radius (radius * radius).
        // If the sum is less than or equal to the radius squared, the circle and rectangle overlap.
        return minY + minX <= radius * radius;
    }
};
