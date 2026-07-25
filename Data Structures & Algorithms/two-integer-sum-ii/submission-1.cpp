class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        while(start < end){
            int found_target = numbers[start]+numbers[end];
            if(found_target == target){
                return {start+1,end+1};
            }
            if(found_target < target){
                start++;
            }
            else end--;
        }
        return {};
    }
};
