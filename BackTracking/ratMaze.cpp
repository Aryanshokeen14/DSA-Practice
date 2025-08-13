#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int maze[][4], int row, int col, vector<vector<bool>> &visited, int n)
{
    return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && !visited[row][col]);
}

void findPaths(int maze[][4], vector<vector<bool>> &visited, int row, int col, int n, string path, vector<string> &result)
{
    // Base case: destination reached
    if (row == n - 1 && col == n - 1)
    {
        result.push_back(path);
        return;
    }

    // Mark current cell as visited
    visited[row][col] = true;

    // Try all four directions
    if (isSafe(maze, row + 1, col, visited, n)) // Down
        findPaths(maze, visited, row + 1, col, n, path + 'D', result);
    if (isSafe(maze, row, col + 1, visited, n)) // Right
        findPaths(maze, visited, row, col + 1, n, path + 'R', result);
    if (isSafe(maze, row - 1, col, visited, n)) // Up
        findPaths(maze, visited, row - 1, col, n, path + 'U', result);
    if (isSafe(maze, row, col - 1, visited, n)) // Left
        findPaths(maze, visited, row, col - 1, n, path + 'L', result);

    // Backtrack
    visited[row][col] = false;
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 1, 1}};

    int n = sizeof(maze)/sizeof(maze[0]);
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> result;

    if (maze[0][0] == 1)
        findPaths(maze, visited, 0, 0, n, "", result);

    if (result.empty())
        cout << "No paths found." << endl;
    else
    {
        cout << "Paths found: " << result.size() << endl;
        for (string path : result)
            cout << path << endl;
    }

    return 0;
}
