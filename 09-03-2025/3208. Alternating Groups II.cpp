//Solution 1
// class Solution {
// public:
//     int numberOfAlternatingGroups(vector<int>& temp, int& k) {

//         for (int i = 0; i < k - 1; i++)
//             temp.push_back(temp[i]);
//         int n = temp.size();
//         int ans = 0;
//         int i = 0;
//         bool pass = false;
//         while (i < n) {
//             if (pass) {
//                 if (temp[i] == temp[i - 1]) {
//                     pass = false;
//                 } else {
//                     ans++;
//                     i++;
//                 }
//             } else {
//                 if (i > n - k)
//                     break;
//                 int j = i;
//                 int last = -1;
//                 while (j < i + k && temp[j] != last) {
//                     last = temp[j];
//                     j++;
//                 }
//                 if (j == i + k) {
//                     ans++;
//                     pass = true;
//                 }
//                 i = j;
//             }
//         }
//         return ans;
//     }
// };


//Solution 2
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0, c = 1, n = colors.size();

        //add first (k - 1) elements to the end (circular)
        for(int i = 0; i < k - 1; i ++){ 
            colors.push_back(colors[i]);
        }
        

        for(int i = 1; i < colors.size(); i ++){
            //if last two elements differ, increase counter
            if(colors[i] ^ colors[i - 1]){
                c ++;
            }else{ //element that breaks the sequence
                res += max(0, c - k + 1); //add number of alternating groups of k elements. if c is less than k, add nothing
                c = 1; //restart counter
            }
        }

        res += max(0, c - k + 1); //check if there is an alternating group at the end that is not added.

        return res;


    }
};