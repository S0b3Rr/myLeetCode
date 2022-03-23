class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int Y = coordinates[1][1] - coordinates[0][1];
	    int X = coordinates[1][0] - coordinates[0][0];     
	    for (int i=2; i < coordinates.size(); i++ ) {
		    if (X * (coordinates[i][1] - coordinates[0][1]) != Y * (coordinates[i][0] - coordinates[0][0]))
			    return false;
	    }
	return true;
    }
};