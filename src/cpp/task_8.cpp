/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

bool canPartition(const std::vector<int>& nums) {
    int totalSum = 0;

    for (int num : nums) {
        totalSum += num;
    }

    if (totalSum % 2 != 0) {
        return false;
    }

    int targetSum = totalSum / 2;
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    std::vector<int> nums1 = {1, 5, 11, 5};
    std::vector<int> nums2 = {1, 2, 3, 5};
    std::vector<int> nums3 = {12, 2, 31, 0, 5};

    std::cout << std::boolalpha << canPartition(nums1) << std::endl; 
    std::cout << std::boolalpha << canPartition(nums2) << std::endl;  
    std::cout << std::boolalpha << canPartition(nums3) << std::endl;  

    return 0;
}
