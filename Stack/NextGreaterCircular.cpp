#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)  
{
    int n = nums.size();  
    stack<int> st;  // Stack to keep track of elements
    // We will traverse the array twice to handle the circular nature
    vector<int> nextGreater;  
    for (int i = 2 * n - 1; i >= 0; i--)   
    {
        while (!st.empty() && st.top() <= nums[i % n])  
            // Pop elements from the stack that are less than or equal to the current element
            // This ensures that we only keep elements that can be the next greater element
            // for the current element in the circular array
        {
            st.pop();
        }
        if (i < n) // Only push results for the first n elements
        {
            st.empty() ? nextGreater.push_back(-1) : nextGreater.push_back(st.top());  // If the stack is empty, there is no next greater element, otherwise take the top of the stack
        }
        st.push(nums[i % n]); // Push the current element onto the stack for the next iterations
    }
    reverse(nextGreater.begin(), nextGreater.end()); // Reverse the result to maintain the original order of the first n elements
    return nextGreater;   
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);
    
    cout << "Next greater elements in circular array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
