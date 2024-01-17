/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <unordered_map>
#include <vector>

bool evaluateClause(const std::vector<int>& clause, const std::unordered_map<char, bool>& assignment) {
    for (int literal : clause) {
        char variable = (literal > 0) ? static_cast<char>('A' + literal - 1) : static_cast<char>('A' - literal - 1);
        bool value = (literal > 0) ? true : false;

        // Check if the literal is satisfied by the assignment
        if (assignment.find(variable) != assignment.end() && assignment.at(variable) == value) {
            return true; // At least one literal in the clause is true
        }
    }

    return false; // No literal in the clause is true
}

bool isSatisfied(const std::vector<std::vector<int>>& formula, const std::unordered_map<char, bool>& assignment) {
    for (const auto& clause : formula) {
        if (!evaluateClause(clause, assignment)) {
            return false; // At least one clause is not satisfied
        }
    }

    return true; // All clauses are satisfied
}

int main() {
    std::vector<std::vector<int>> formula = {{1, -2}, {-1, 2, 3}};
    std::unordered_map<char, bool> assignment = {{'A', true}, {'B', false}, {'C', true}};

    bool result = isSatisfied(formula, assignment);

    if (result) {
        std::cout << "Satisfied" << std::endl;
    } else {
        std::cout << "Not Satisfied" << std::endl;
    }

    return 0;
}
