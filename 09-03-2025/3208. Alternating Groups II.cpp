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