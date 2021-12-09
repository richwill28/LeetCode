class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> interval1, vector<int> interval2){ return interval1[0] < interval2[0]; });

        vector<vector<int>> mergedIntervals;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                mergedIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        mergedIntervals.push_back({start, end});

        return mergedIntervals;
    }
};
