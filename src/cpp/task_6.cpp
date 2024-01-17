/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Edge {
    int target;
    int weight;
};

int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
  
    std::vector<std::vector<Edge>> graph(n + 1);
    for (const auto& time : times) {
        graph[time[0]].push_back({time[1], time[2]});
    }

    std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
    dist[k] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        if (currentDist > dist[currentNode]) {
            continue; // Skip outdated entries in the priority queue
        }

        for (const auto& edge : graph[currentNode]) {
            int newDist = currentDist + edge.weight;

            if (newDist < dist[edge.target]) {
                dist[edge.target] = newDist;
                pq.push({newDist, edge.target});
            }
        }
    }

    int maxDistance = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == std::numeric_limits<int>::max()) {
            return -1; // There is an unreachable node
        }
        maxDistance = std::max(maxDistance, dist[i]);
    }

    return maxDistance;
}


