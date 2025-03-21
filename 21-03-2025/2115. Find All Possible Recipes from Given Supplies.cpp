class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        for (size_t i = 0; i < recipes.size(); ++i) {
            adj[recipes[i]] = ingredients[i];
        }

        unordered_set<string> sup(supplies.begin(), supplies.end());

        unordered_map<string, bool> canMake;

        queue<string> q;

        for (const auto& recipe : recipes) {
            bool canBeMade = true;
            for (const auto& ingredient : adj[recipe]) {
                if (sup.find(ingredient) == sup.end()) {
                    canBeMade = false;
                    break;
                }
            }
            if (canBeMade) {
                q.push(recipe);
                canMake[recipe] = true;
            }
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            for (auto& [rec, ing] : adj) {
                if (canMake.find(rec) != canMake.end())
                    continue;

                bool made = true;
                for (const auto& ingredient : ing) {
                    if (sup.find(ingredient) == sup.end() &&
                        canMake.find(ingredient) == canMake.end()) {
                        made = false;
                        break;
                    }
                }

                if (made) {
                    canMake[rec] = true;
                    q.push(rec);
                }
            }
        }

        vector<string> ans;
        for (const auto& rec : recipes) {
            if (canMake[rec]) {
                ans.push_back(rec);
            }
        }

        return ans;
    }
};











class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> sup(supplies.begin(), supplies.end());
        vector<string> ans;
        int n = recipes.size();
        vector<bool> complete(n, false);
        
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);

        while (!q.empty()) {
            int size = q.size();
            bool made = false;

            for (int j = 0; j < size; j++) { 
                int i = q.front(); 
                q.pop();
                
                if (complete[i]) continue;

                bool canMake = true;
                for (const auto& ing : ingredients[i]) {
                    if (sup.find(ing) == sup.end()) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    sup.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    complete[i] = true;
                    made = true;
                } else {
                    q.push(i);
                }
            }

            if (!made) break;
        }

        return ans;
    }
};
