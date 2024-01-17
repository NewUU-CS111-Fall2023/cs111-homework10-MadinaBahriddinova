/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

bool evaluateClause(const std::vector<int>& clause, const std::vector<bool>& assignment) {
    for (int literal : clause) {
        int variable = std::abs(literal);
        bool isNegated = (literal < 0);

        if (assignment[variable - 1] == !isNegated) {
            return true;  // At least one literal in the clause is true
        }
    }

    return false;  // No literal in the clause is true
}

bool isSatisfied(const std::vector<std::vector<int>>& cnfFormula, const std::vector<bool>& assignment) {
    for (const auto& clause : cnfFormula) {
        if (!evaluateClause(clause, assignment)) {
            return false;  // At least one clause is not satisfied
        }
    }

    return true;  // All clauses are satisfied
}

bool bruteForceSatisfiability(const std::vector<std::vector<int>>& cnfFormula) {
    int numVariables = 0;

    for (const auto& clause : cnfFormula) {
        for (int literal : clause) {
            numVariables = std::max(numVariables, std::abs(literal));
        }
    }

    for (int i = 0; i < (1 << numVariables); ++i) {
        std::vector<bool> assignment(numVariables);

        for (int j = 0; j < numVariables; ++j) {
            assignment[j] = ((i >> j) & 1) != 0;
        }
        if (isSatisfied(cnfFormula, assignment)) {
            return true;
        }
    }

    return false;
}

