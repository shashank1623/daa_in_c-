/*

problem statement:-
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

solution:-
*/

//Need to store the wage/quality ratio & quality for each worker and sort it 
//Now traverse worker and store it in a k-max heap, where heap stroes the quality with top max quality at top.
//keep on storing sum of each quality of k elements stored in pq.
//As we move from lower ratio worker to higher ratio, when stored k elements in queue then evaluate the total wage by multiplying highest ratio with the sum of all quality stored till now.
//To minimize the overall wage, we need to remove the largest quality from the queue

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> rq;
        for(int i = 0; i < quality.size(); ++i) {
            rq.push_back({double(wage[i])/quality[i], quality[i]});
        }
        sort(rq.begin(), rq.end());
        priority_queue<int> pq;
        int sum = 0;
        double ans = DBL_MAX;
        for(auto i: rq){
            sum += i.second;
            pq.push(i.second);
            if(pq.size() > k)  { sum -= pq.top(); pq.pop(); } 
            if(pq.size() == k) { ans = min(ans, sum*i.first); }
        }
        return ans;
    }
};

//problem link:- https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
