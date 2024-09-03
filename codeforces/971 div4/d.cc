#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int, int> Point;

// Helper function to calculate the slope between two points
pair<int, int> calculateSlope(const Point& p1, const Point& p2) {
    int dy = p2.second - p1.second;
    int dx = p2.first - p1.first;
    
    // Handle vertical line
    if (dx == 0) return {1, 0};
    // Handle horizontal line
    if (dy == 0) return {0, 1};
    
    // Simplify the slope by dividing by gcd(dy, dx)
    int gcd = __gcd(abs(dy), abs(dx));
    dy /= gcd;
    dx /= gcd;
    
    // Ensure the slope is always in the same direction
    if (dx < 0) {
        dx = -dx;
        dy = -dy;
    }
    
    return {dy, dx};
}

int countRightTriangles(const vector<Point>& points) {
    int n = points.size();
    int rightTriangles = 0;
    
    for (int i = 0; i < n; ++i) {
        map<pair<int, int>, int> slopeCount;
        
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            
            pair<int, int> slope = calculateSlope(points[i], points[j]);
            
            // Increase the count of this slope from the current point
            slopeCount[slope]++;
        }
        
        // Now, check for each unique slope and its perpendicular counterpart
        for (auto& [slope, count] : slopeCount) {
            pair<int, int> perpSlope = {-slope.second, slope.first}; // Perpendicular slope
            
            // If we find the perpendicular slope, calculate possible triangles
            if (slopeCount.find(perpSlope) != slopeCount.end()) {
                rightTriangles += count * slopeCount[perpSlope];
            }
        }
    }
    
    // Each triangle is counted twice, so divide the result by 2
    return rightTriangles / 2;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        
        cout << countRightTriangles(points) << endl;
    }
    
    return 0;
}
