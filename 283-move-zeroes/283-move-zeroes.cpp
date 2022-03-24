class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
        /*
        remove() 将待删除的元素转移至vector的末尾并返回指向第一个待删除元素的迭代器
        fill()   迭代替换
        */
    }
};