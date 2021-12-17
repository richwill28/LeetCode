class Solution {
private:
    // 3-way partition
    int partition(vector<pair<int, int>>& arr, int lowerIndex, int upperIndex) {
        int pivot = arr[lowerIndex].first;
        int currentIndex = lowerIndex;
        for (int i = lowerIndex + 1; i <= upperIndex; i++) {
            if (arr[i].first <= pivot) {
                currentIndex++;
                swap(arr[i], arr[currentIndex]);
            }
        }
        swap(arr[lowerIndex], arr[currentIndex]);
        int pivotIndex = currentIndex;
        for (int i = lowerIndex; i < pivotIndex; i++) {
            if (arr[i].first == arr[currentIndex].first) {
                currentIndex--;
                swap(arr[i], arr[currentIndex]);
            }
        }
        return pivotIndex;
    }

    // Select the index of k-th smallest element
    int quickSelect(vector<pair<int, int>>& arr, int lowerIndex, int upperIndex, int k) {
        if (k > 0 && k <= upperIndex - lowerIndex + 1) {
            int pivotIndex = partition(arr, lowerIndex, upperIndex);
            int position = pivotIndex - lowerIndex;
            if (position == k - 1) {
                return pivotIndex;
            } else if (position > k - 1) {
                // position is more, recur to left side
                return quickSelect(arr, lowerIndex, pivotIndex - 1, k);
            } else if (position < k - 1) {
                // position is less, recur to right side
                return quickSelect(arr, pivotIndex + 1, upperIndex, k - (position + 1));
            }
        }
        return -1;
    }

public:
    // Using max heap
    // O(n log n) time and O(n + n) size complexity
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto& num : nums) {    // costs O(n)
            hashMap[num]++;
        }

        priority_queue<pair<int, int>> maxPQ;   // pair = {frequency, number}
        for (auto& elem : hashMap) {    // costs O(n log n)
            maxPQ.push({elem.second, elem.first});
        }

        vector<int> solution;
        while (k--) {   // costs O(k log n)
            int num = maxPQ.top().second;
            maxPQ.pop();
            solution.push_back(num);
        }
        return solution;
    }

    // Using min heap (slightly more efficient)
    // O(n log k) time and O(n + k) size complexity
    // Actually, O(n log k) == O(n log n) because k <= n
    // To achieve true O(n log k), we can consider k == n input and terminate early
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto& num : nums) {    // costs O(n)
            hashMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;  // pair = {frequency, number}
        for (auto& elem : hashMap) {    // costs O(n log k)
            minPQ.push({elem.second, elem.first});
            if (minPQ.size() > k) {
                minPQ.pop();
            }
        }

        vector<int> solution;
        while (k--) {   // costs O(k log k)
            int num = minPQ.top().second;
            minPQ.pop();
            solution.push_back(num);
        }
        return solution;
    }

    // Using quick select
    // Average O(n) and worst-case O(n^2) time complexity
    // O(n) size complexity
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto& num : nums) {    // costs O(n)
            hashMap[num]++;
        }

        vector<pair<int, int>> unique;  // pair = {frequency, num}
        for (auto& elem : hashMap) {    // costs O(n)
            unique.push_back({elem.second, elem.first});
        }

        vector<int> solution;
        int index = quickSelect(unique, 0, unique.size() - 1, unique.size() - k + 1);   // costs O(n)
        for (int i = index; i < unique.size(); i++) {   // costs O(n)
            solution.push_back(unique[i].second);
        }
        return solution;
    }

    // Using bucket sort
    // O(n) time and O(n) size complexity
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for (auto& num : nums) {    // costs O(n)
            hashMap[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1, vector<int>()); // bucket index is frequency (works because frequency is at most n)
        for (auto& elem : hashMap) {    // costs O(n)
            bucket[elem.second].push_back(elem.first);
        }

        vector<int> solution;
        for (int i = bucket.size() - 1; i >= 0; i--) {  // costs O(n)
            if (k == 0) {
                break;
            }

            if (bucket[i].size() > 0) {
                for (auto& num : bucket[i]) {
                    solution.push_back(num);
                    k--;
                }
            }
        }
        return solution;
    }
};
