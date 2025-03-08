class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //res is final answer, c is counter
        int res, c = 0;

        //count number of white block in first k blocks
        for(int i = 0; i < k; i ++){
            if(blocks[i] == 'W')c ++;
        }
        //set res = c
        res = c;

        //check if a better answer exists, shift a block every time
        for(int i = k; i < blocks.size(); i ++){
            //add a new block to the right, if it's white increase c
            if(blocks[i] == 'W')c ++;
            //leave the first block from the left, if it's white decrease c
            if(blocks[i - k] == 'W')c --;
            //now you have a new set of k blocks
            //check if number of white blocks is less
            res = min(res, c);
        }

        return res;

    }
};