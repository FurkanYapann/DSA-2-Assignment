#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool isValid(int x, int y, int R, int C) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void wordBoggleUtil(int x, int y, int R, int C, vector<vector<char>>& board, string& current, unordered_set<string>& dictionary, vector<string>& result, vector<vector<bool>>& visited) {
    if (dictionary.find(current) != dictionary.end()) {
        result.push_back(current);
        dictionary.erase(current);
    }

    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY, R, C) && !visited[newX][newY]) {
            visited[newX][newY] = true;
            current.push_back(board[newX][newY]);
            wordBoggleUtil(newX, newY, R, C, board, current, dictionary, result, visited);
            current.pop_back();
            visited[newX][newY] = false;
        }
    }
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    int R = board.size();
    int C = board[0].size();

    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<string> result;
    string current = "";
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            visited[i][j] = true;
            current.push_back(board[i][j]);
            wordBoggleUtil(i, j, R, C, board, current, dict, result, visited);
            current.pop_back();
            visited[i][j] = false;
        }
    }

    return result;
}

int main() {
    int N = 4;
    vector<string> dictionary = { "GEEKS", "FOR", "QUIZ", "GO" };
    int R = 3, C = 3;
    vector<vector<char>> board = { {'G', 'I', 'Z'},
                                   {'U', 'E', 'K'},
                                   {'Q', 'S', 'E'} };
    vector<string> result = wordBoggle(board, dictionary);
    for (const auto& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
