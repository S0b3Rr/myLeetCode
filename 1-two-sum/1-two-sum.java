class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> indexMap = new HashMap<Integer,Integer>();
        for(int i = 0; i < nums.length; i++){
            int targetNum = (Integer)(target - nums[i]);
            if(indexMap.containsKey(targetNum)){
                int ans[] = {indexMap.get(targetNum), i};
                return ans;
            }

            indexMap.put(nums[i], i);
        }
        return null;
    }
}