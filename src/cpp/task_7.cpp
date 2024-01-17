/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <unordered_map>

int minRabbits(const std::vector<int>& answers) {
    std::unordered_map<int, int> count;

    for (int ans : answers) {
        count[ans]++;
    }

    int totalRabbits = 0;

    for (auto& entry : count) {
        int groupSize = entry.first + 1;
        int rabbitCount = entry.second;
        int cliques = (rabbitCount + groupSize - 1) / groupSize;

        totalRabbits += cliques * groupSize;
    }

    return totalRabbits;
}

int main() {
    std::vector<int> answers = {1, 1, 2};

    int result = minRabbits(answers);

    std::cout << result << std::endl;

    return 0;
}
