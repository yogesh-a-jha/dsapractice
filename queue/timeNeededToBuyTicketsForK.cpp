class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }

        int time=0;
        while(1){
            if(tickets[k]==0){
                return time;
            }
            tickets[q.front()]--;
            if(tickets[q.front()]>0){
            q.push(q.front());

            }
            q.pop();
            time++;
        }

        // return time;
    }
};