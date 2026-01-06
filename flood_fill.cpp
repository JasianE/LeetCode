#include <vector>
using namespace std;

class Solution {
public:
void dfs(int r, int c, vector<vector<int>>&image, int og_color, int color){
            if((r < 0 || r >= image.size()) || (c<0 || c>=image[r].size()) || (image[r][c] != og_color)){
                return;
            }
            image[r][c] = color;
            dfs(r, c-1, image, og_color, color);
            dfs(r,c+1, image,og_color, color);
            dfs(r+1, c,image,og_color, color);
            dfs(r-1,c,image,og_color, color);
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //a DFS algortihm
        int og_color = image[sr][sc];
        
        if(color == og_color){
            return image;
        }

    
        dfs(sr,sc,image, og_color, color);
        return image;
    }
};