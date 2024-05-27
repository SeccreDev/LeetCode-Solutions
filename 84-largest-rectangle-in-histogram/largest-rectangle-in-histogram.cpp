class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> prev; // Stores the index of the previous smaller element for each element
        vector<int> next; // Stores the index of the next smaller element for each element
        previous(prev, heights.data(), n); // Calculate the previous array
        nexts(next, heights.data(), n); // Calculate the next array
        vector<int> ans; // Stores the area of each rectangle
        reverse(next.begin(), next.end()); // Reverse the next array for easier calculation
        for(int i = 0; i < n; i++)
        {
            ans.push_back(heights[i] * (next[i] - prev[i] - 1)); // Calculate area for each element
        }
        return *max_element(ans.begin(), ans.end()); // Return the maximum area
    }

    // Function to calculate the previous array
    void previous(vector<int>& prev, int *arr, int n)
    {
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop(); // Remove elements greater than or equal to arr[i] from stack
            }
            if(st.empty())
            {
                prev.push_back(-1); // If stack is empty, there is no previous smaller element
            }
            else
            {
                prev.push_back(st.top()); // Otherwise, store the index of the previous smaller element
            }
            st.push(i); // Push current element index onto stack
        }
    }

    // Function to calculate the next array
    void nexts(vector<int>& next, int *arr, int n)
    {
        stack<int> st;
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop(); // Remove elements greater than or equal to arr[i] from stack
            }
            if(st.empty())
            {
                next.push_back(n); // If stack is empty, there is no next smaller element, so n is used
            }
            else
            {
                next.push_back(st.top()); // Otherwise, store the index of the next smaller element
            }
            st.push(i); // Push current element index onto stack
        }
    }
};