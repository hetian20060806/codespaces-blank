#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>>dp(m, vector<bool>(n, false));
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int total = m * n;
        for (auto& wall : walls) {
            dp[wall[0]][wall[1]] = true;
            total--;
        }
        for (auto& guard : guards) {
            total--;
            visited[guard[0]][guard[1]] = true;
        }
        for (auto& guard : guards) {
            //向北看
            for (int i = guard[0] - 1; i >= 0; i--) {
                if (!dp[i][guard[1]]) {
                    if (!visited[i][guard[1]]) {
                        visited[i][guard[1]] = true;
                        total--;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            //向南看
            for (int i = guard[0] + 1; i < m; i++) {
                if (!dp[i][guard[1]]) {
                    if (!visited[i][guard[1]]) {
                        visited[i][guard[1]] = true;
                        total--;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            //向西看
            for (int i = guard[1] - 1; i >= 0; i--) {
                if (!dp[guard[1]][i]) {
                    if (!visited[guard[0]][i]) {
                        visited[guard[0]][i] = true;
                        total--;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            //向东看
            for (int i = guard[1] + 1; i < n; i++) {
                if (!dp[guard[0]][i]) {
                    if (!visited[guard[0]][i]) {
                        visited[guard[0]][i] = true;
                        total--;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    break;
                }
            }
        }
        return total;
    }
};
int main() {
    int m, n;
    cin >> m >> n;
    int num, numm;
    cin >> num >> numm;
    vector<vector<int>>guards;
    for (int i = 0; i < num; i++) {
        int first, second;
        cin >> first >> second;
        guards.push_back({ first, second });
    }
    vector<vector<int>>walls;
    for (int i = 0; i < numm; i++) {
        int first, second;
        cin >> first >> second;
        walls.push_back({ first, second });
    }
    Solution solution;
    cout << solution.countUnguarded(m,n,guards, walls);
    return 0;
}

