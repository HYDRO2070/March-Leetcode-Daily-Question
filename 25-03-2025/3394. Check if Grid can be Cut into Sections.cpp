// Brute Force - Memory Limit overflow


// class Solution {
// private:
//     bool solve(const unordered_map<int, vector<int>>& arr) {
//         unordered_map<int, bool> visit; // Tracks visited indices
//         int cnt = 0;

//         auto it = arr.begin();
//         if (it == arr.end()) return false;
        
//         for (int num : it->second) visit[num] = true;

//         for (++it; it != arr.end(); ++it) {
//             const auto& indices = it->second;
//             if (indices.empty()) continue;

//             bool flag = true;
//             for (int num : indices) {
//                 if (visit[num]) flag = false;
//                 visit[num] = true;
//             }
//             if (flag) cnt++;
//         }

//         return cnt >= 2;
//     }

// public:
//     bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
//         unordered_map<int, vector<int>> hor, ver;
//         int index = 1;

//         for (auto& rec : rectangles) {
//             for (int i = rec[0]; i < rec[2]; i++) {
//                 hor[i].push_back(index);
//             }
//             for (int i = rec[1]; i < rec[3]; i++) {
//                 ver[i].push_back(index);
//             }
//             index++;
//         }

//         return solve(hor) || solve(ver);
//     }
// };




// Optimized
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return helper(rectangles, 0) || helper(rectangles, 1);
    }
private:
    bool helper(vector<vector<int>>& rectangles, int cor){
        int cuts = 0;
        sort(rectangles.begin(), rectangles.end(), [cor]
            (const vector<int>& a, const vector<int>& b){
                return a[cor] < b[cor];
            }
        );
        int end = rectangles[0][cor + 2];
        for(int i = 1; i < rectangles.size(); i++){
            if(end <= rectangles[i][cor])
                cuts++;
            end = max(end, rectangles[i][cor + 2]);
        }
        if(cuts >= 2)   return true;
        return false;
    }
};
