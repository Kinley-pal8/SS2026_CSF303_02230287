#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> toll(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> toll[i];
    }
    
    // dp[i][j][skips] = minimum time to reach booth i with j coins remaining and 'skips' skips used
    // Since this can be large, use BFS/Dijkstra approach
    // State: (time, booth, coins, skips_used)
    
    const int INF = 1e9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, INF)));
    
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    
    // Start at booth 1 with m coins and 0 skips
    dp[1][m][0] = 0;
    pq.push({0, 1, m, 0});
    
    while (!pq.empty()) {
        auto [time, booth, coins, skips] = pq.top();
        pq.pop();
        
        if (time > dp[booth][coins][skips]) continue;
        
        if (booth == n) continue;
        
        // Option 1: Pay toll and move to next booth
        if (coins >= toll[booth]) {
            int newTime = time + 1;
            int newCoins = coins - toll[booth];
            int newBooth = booth + 1;
            
            if (newTime < dp[newBooth][newCoins][skips]) {
                dp[newBooth][newCoins][skips] = newTime;
                pq.push({newTime, newBooth, newCoins, skips});
            }
        }
        
        // Option 2: Skip booth (if we have skips left)
        if (skips < k) {
            int newTime = time + 2;
            int newBooth = booth + 1;
            
            if (newTime < dp[newBooth][coins][skips + 1]) {
                dp[newBooth][coins][skips + 1] = newTime;
                pq.push({newTime, newBooth, coins, skips + 1});
            }
        }
    }
    
    // Find minimum time to reach booth n
    int result = INF;
    for (int j = 0; j <= m; j++) {
        for (int s = 0; s <= k; s++) {
            result = min(result, dp[n][j][s]);
        }
    }
    
    if (result == INF) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}
