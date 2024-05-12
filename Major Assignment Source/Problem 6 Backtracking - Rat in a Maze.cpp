#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int x, int y, int N, vector<vector<int>>& maze) {
    return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
}

void ratMazeHelper(int x, int y, int N, vector<vector<int>>& maze, vector<string>& path, string& currentPath) {
    if (x == N - 1 && y == N - 1) {
        path.push_back(currentPath);
        return;
    }

    if (isSafe(x + 1, y, N, maze)) {
        maze[x][y] = 0;
        currentPath.push_back('D');
        ratMazeHelper(x + 1, y, N, maze, path, currentPath);
        currentPath.pop_back();
        maze[x][y] = 1;
    }

    if (isSafe(x, y + 1, N, maze)) {
        maze[x][y] = 0;
        currentPath.push_back('R');
        ratMazeHelper(x, y + 1, N, maze, path, currentPath);
        currentPath.pop_back();
        maze[x][y] = 1;
    }

    if (isSafe(x - 1, y, N, maze)) {
        maze[x][y] = 0;
        currentPath.push_back('U');
        ratMazeHelper(x - 1, y, N, maze, path, currentPath);
        currentPath.pop_back();
        maze[x][y] = 1;
    }

    if (isSafe(x, y - 1, N, maze)) {
        maze[x][y] = 0;
        currentPath.push_back('L');
        ratMazeHelper(x, y - 1, N, maze, path, currentPath);
        currentPath.pop_back();
        maze[x][y] = 1;
    }
}

vector<string> printPath(int N, vector<vector<int>>& maze) {
    vector<string> path;
    string currentPath = "";
    ratMazeHelper(0, 0, N, maze, path, currentPath);
    return path;
}

int main() {
    int N = 4;
    vector<vector<int>> maze = { {1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {1, 1, 0, 0},
                                 {0, 1, 1, 1} };
    vector<string> paths = printPath(N, maze);
    for (const auto& path : paths) {
        cout << path << " ";
    }
    cout << endl;
    return 0;
}
