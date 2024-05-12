#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, int color, vector<int>& graphColor, vector<vector<int>>& graph, int N, int M) {
    for (int i = 0; i < N; ++i) {
        if (graph[node][i] && color == graphColor[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int node, int M, vector<int>& graphColor, vector<vector<int>>& graph, int N) {
    if (node == N) {
        return true;
    }

    for (int color = 1; color <= M; ++color) {
        if (isSafe(node, color, graphColor, graph, N, M)) {
            graphColor[node] = color;
            if (graphColoringUtil(node + 1, M, graphColor, graph, N)) {
                return true;
            }
            graphColor[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int N, vector<vector<int>>& graph, int M) {
    vector<int> graphColor(N, 0);

    if (!graphColoringUtil(0, M, graphColor, graph, N)) {
        return false;
    }

    return true;
}

int main() {
    int N = 4;
    int M = 3;
    vector<vector<int>> graph = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };
    cout << graphColoring(N, graph, M) << endl;

    return 0;
}
