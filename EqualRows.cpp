class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
    unordered_map<string, int> rows_columns;
    int n = grid.size();
    int pairs = 0;

    // Store rows as strings
    for (int i = 0; i < n; i++) {
        string row_str;
        for (int j = 0; j < n; j++) {
            row_str += to_string(grid[i][j]) + ","; 
        }
        rows_columns[row_str]++;
    }

    // Compare columns
    for (int i = 0; i < n; i++) {
        string col_str;
        for (int j = 0; j < n; j++) {
            col_str += to_string(grid[j][i]) + ","; 
        }
        if (rows_columns.count(col_str)) {
            pairs += rows_columns[col_str];
        }
    }
    return pairs;
}
};


       /* 
       18 18 18 18 18
       18 18 18 18 17
       18 18 18 18 18
       18 18 18 18 18
       18 18 18 18 18
        

       */
