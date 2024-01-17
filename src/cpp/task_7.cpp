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


