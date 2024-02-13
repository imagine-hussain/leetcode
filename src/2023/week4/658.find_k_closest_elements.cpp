#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end());

        cout << "start" << endl;
        int lo = bsearch_idx(arr, x, 0, arr.size() - 1);
        cout << "found: " << lo << endl;

        if (lo == -1)
            return vector<int>();

        int hi = lo;

        int n = arr.size();
        while ((hi - lo) < k) {
            cout << "lo:hi" << "\t" << lo << "\t" << hi;
            int l = arr[lo];
            int r = arr[hi];
            if (abs(x - l) < abs(l - r)) {
                if (lo > 0) lo--; else hi++;
            } else {
                if (hi < n -1) hi++; else lo--;
            }
            cout << endl;
        }
        cout << "exit" << endl;


        return vector<int>(arr.begin() + lo, arr.begin() + hi);
    }

    int bsearch_idx(vector<int>& arr, int target, int lo, int hi) {
        int closest_idx = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (abs(arr[i] - target) < abs(arr[closest_idx] - target))
                closest_idx = i;
        }
        // while (lo <= hi) {
        //     int mid = (lo + hi) / 2;
        //     // update idx
        //     if (arr[mid] < target) {
        //         lo = mid + 1;
        //     } else if (arr[mid] > target) {
        //         hi = mid - 1;
        //     } else {
        //         return mid;
        //     }
        // }

        return closest_idx;
    }

};
