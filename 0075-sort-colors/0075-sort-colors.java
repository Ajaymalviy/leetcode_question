class Solution {
  public void sortColors(int[] nums) {
    int start = 0;
    int end = nums.length - 1;
    int index = 0;
    while (index <= end) {
      if (nums[index] == 0) {
        swap(nums, start++, index++);
      } else if (nums[index] == 1) {
        index++;
      } else {
        swap(nums, end--, index);
      }
    }
  }

  
  
  private void swap(int[] nums, int index1, int index2) {
    int tmp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = tmp;
  }
}
