class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            mergedIntervals.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        int start = newInterval[0];
        int end = newInterval[1];
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
            i++;
        }
        mergedIntervals.push_back({start, end});

        while (i < intervals.size()) {
            mergedIntervals.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return mergedIntervals;
    }
};
