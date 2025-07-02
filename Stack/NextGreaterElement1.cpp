#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreaterMap; // Map to store the next greater element for each number in nums2
    stack<int> st; // Stack to keep track of elements for which we need to find the next greater element

    // Traverse nums2 from right to left
    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop(); // Pop elements that are less than or equal to the current element
        }
        if (st.empty()) {
            nextGreaterMap[nums2[i]] = -1; // No greater element found
        } else {
            nextGreaterMap[nums2[i]] = st.top(); // The top of the stack is the next greater element
        }
        st.push(nums2[i]); // Push the current element onto the stack
    }

    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreaterMap[num]); // Fill the result with the next greater elements for nums1
    }
    
    return result;
}

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = nextGreaterElement(nums1, nums2);
    
    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}