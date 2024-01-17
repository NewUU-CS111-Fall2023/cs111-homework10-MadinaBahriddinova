/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

bool hasZeroSumTriplet(const std::vector<int>& numbers) {
    int n = numbers.size();

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (numbers[i] + numbers[j] + numbers[k] == 0) {
                    return true;  
                }
            }
        }
    }

    return false;  
}

int main() {
    std::vector<int> numbers = {-5, -17, 7, -4, 3, -2, 4};

    bool result = hasZeroSumTriplet(numbers);

    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
