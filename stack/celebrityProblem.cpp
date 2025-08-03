class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        stack<int> st;

        // Push all people into stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int first = st.top(); st.pop();
            int second = st.top(); st.pop();

            if (mat[first][second]) {
                // first knows second → first is not celeb
                st.push(second);
            } else {
                // first doesn't know second → second is not celeb
                st.push(first);
            }
        }

        // Potential celebrity
        if (st.empty()) return -1;
        int num = st.top(); st.pop();

        // Final check: num should know no one and everyone should know num
        for (int i = 0; i < n; i++) {
            if (i != num && (mat[num][i] == 1 || mat[i][num] == 0)) {
                return -1;
            }
        }

        return num;
    }
};