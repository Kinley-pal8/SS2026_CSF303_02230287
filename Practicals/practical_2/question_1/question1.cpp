#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> allergies(n, 0);
        
        // Read allergies as bitmask
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int allergy;
                cin >> allergy;
                allergies[i] |= (1 << (allergy - 1));
            }
        }
        
        // Precompute conflicts: conflict[i][j] = true if persons i and j can't sit adjacent
        vector<vector<bool>> conflict(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (allergies[i] & allergies[j]) {
                    conflict[i][j] = conflict[j][i] = true;
                }
            }
        }
        
        // DP for circular arrangement
        // dp[mask][i] = true if we can arrange persons in mask starting from person 0 and ending at person i
        vector<vector<bool>> dp(1 << n, vector<bool>(n, false));
        
        // Base case: start with person 0
        dp[1][0] = true;
        
        // Fill DP table
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int last = 0; last < n; last++) {
                if (!(mask & (1 << last)) || !dp[mask][last]) continue;
                
                // Try to add each unvisited person
                for (int next = 0; next < n; next++) {
                    if ((mask & (1 << next)) || conflict[last][next]) continue;
                    
                    dp[mask | (1 << next)][next] = true;
                }
            }
        }
        
        // Check if full circular arrangement exists
        // It exists if we can visit all persons and the last person doesn't conflict with person 0
        int fullMask = (1 << n) - 1;
        bool found = false;
        
        for (int i = 0; i < n; i++) {
            if (dp[fullMask][i] && !conflict[i][0]) {
                found = true;
                break;
            }
        }
        
        cout << (found ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
