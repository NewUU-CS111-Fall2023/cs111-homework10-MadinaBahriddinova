/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> generate3SAT(int variables, int clauses) {
    std::srand(std::time(0));

    std::vector<std::vector<int>> formula;

    for (int i = 0; i < clauses; ++i) {
        std::vector<int> clause;

        for (int j = 0; j < 3; ++j) {
            int variable = std::rand() % variables + 1;
            int sign = std::rand() % 2 == 0 ? 1 : -1;

            clause.push_back(sign * variable);
        }

        formula.push_back(clause);
    }

    return formula;
}

void print3SAT(const std::vector<std::vector<int>>& formula) {
    for (const auto& clause : formula) {
        std::cout << "(";
        for (int i = 0; i < 3; ++i) {
            char variable = (clause[i] > 0) ? static_cast<char>('A' + clause[i] - 1) : static_cast<char>('A' - clause[i] - 1);
            std::cout << variable;

            if (i < 2) {
                std::cout << " | ";
            }
        }
        std::cout << ")";
        if (&clause != &formula.back()) {
            std::cout << " & ";
        }
    }
    std::cout << std::endl;
}

