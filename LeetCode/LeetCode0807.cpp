//
//  main.cpp
//  LeetCode0807
//
//  Created by Nuri Ra on 27.02.19.
//  Copyright © 2019 Nuri Ra. All rights reserved.
//

//Runtime: 16 ms, faster than 13.70% of C++ online submissions for Max Increase to Keep City Skyline.
//Memory Usage: 10.4 MB, less than 6.54% of C++ online submissions for Max Increase to Keep City Skyline.

#include <iostream>
#include <vector>

int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
    std::vector<int> top;
    std::vector<int> left;
    std::vector<std::vector<int>> gridNew = grid;
    int i, j, result = 0;
    
    // Left or right skyline
    for(i = 0 ; i < grid.size() ; i++)
    {
        top.push_back(grid[i][0]);
        
        for(j = 1 ; j < grid.size() ; j++)
            if(top[i] < grid[i][j])
                top[i] = grid[i][j];
    }
    
    for(i = 0; i < grid.size() ; i++)
        std::cout << top[i] << " ";
    std::cout << "\n";
    
    // Top or bottom skyline
    for(i = 0 ; i < grid.size() ; i++)
    {
        left.push_back(grid[0][i]);
        
        for(j = 1 ; j < grid.size() ; j++)
            if(left[i] < grid[j][i])
                left[i] = grid[j][i];
    }
    
    for(i = 0; i < grid.size() ; i++)
        std::cout << left[i] << " ";
    std::cout << "\n";
    
    for(i = 0 ; i < grid.size() ; i++)
        for(j = 0 ; j < grid.size() ; j++)
            if(grid[i][j] < top[i] && grid[i][j] < left[j])
            {
                if(top[i] > left[j])
                    gridNew[i][j] = left[j];
                gridNew[i][j] = top[i];
            }
    
    for(i = 0 ; i < grid.size() ; i++)
        for(j = 0 ; j < grid.size() ; j++)
        {
            gridNew[i][j] = gridNew[i][j] - grid[i][j];
            std::cout << i << " : " << j << " = " << gridNew[i][j] << "\n";
            result += gridNew[i][j];
        }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::vector<std::vector<int>> grid = {{13,47,91,34,20,33,39,22,80,62},{73,97,88,51,38,36,52,75,25,99},{95,43,32,26,82,74,60,69,59,55},{20,41,77,95,79,46,70,50,17,51},{51,0,93,27,46,41,58,49,8,5},{92,58,38,56,73,93,34,47,23,62},{97,66,57,72,26,46,4,90,82,74},{7,44,67,96,0,82,75,22,53,100},{95,48,46,68,41,53,69,42,13,87},{79,48,96,39,21,35,3,12,22,42}};
    
    int result = maxIncreaseKeepingSkyline(grid);
    
    std::cout << result << "\n";
    return 0;
}
