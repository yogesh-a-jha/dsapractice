class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long mul = 1;
        vector<int>row;
        row.push_back(mul);
        for(int i = 1 ; i<=rowIndex ; i++){
            mul = mul * (rowIndex - i +1);
            mul = mul / i;
            row.push_back(mul);
        }

        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ;
        for(int i = 0; i<numRows ; i++){
            ans.push_back(getRow(i));
        }
        return ans;
    }

};