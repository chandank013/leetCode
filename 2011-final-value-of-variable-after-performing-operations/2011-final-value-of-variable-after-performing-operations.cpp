class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int X = 0;

        for ( int i = 0; i < operations.size(); i++)
        {
            if ( operations[i][1] == '+')
            {
                X++;
            }
            else
            {
                X--;
            }
           
        }
        return X;
    }
};