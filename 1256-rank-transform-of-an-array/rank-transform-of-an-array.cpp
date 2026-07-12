class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    
    vector<int> temp = arr;          // Copy original array
    
    sort(temp.begin(), temp.end());  // Sort the copy
    
    unordered_map<int, int> rank;    // Store number -> rank
    
    int r = 1;
    
    for(int num : temp) {
        if(rank.find(num) == rank.end()) {
            rank[num] = r;
            r++;
        }
    }
    
    vector<int> result;
    
    for(int num : arr) {
        result.push_back(rank[num]);
    }
    
    return result;
}
};