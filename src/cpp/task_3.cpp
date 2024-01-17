/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <tuple>

enum class State {
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
};

std::tuple<State, char, char, char> transition(State current, char symbol) {
    switch (current) {
        case State::Q0:
            if (symbol == '1') return {State::Q1, 'X', 'R', '0'};
            else return {State::Q0, symbol, 'R', '0'};
        case State::Q1:
            if (symbol == '1') return {State::Q1, '1', 'R', '1'};
            else if (symbol == 'c') return {State::Q2, 'B', 'R', '1'};
            else return {State::Q1, symbol, 'R', '1'};
        case State::Q2:
            if (symbol == '1') return {State::Q3, 'B', 'L', '1'};
            else return {State::Q2, symbol, 'R', '1'};
        case State::Q3:
            if (symbol == '1') return {State::Q3, '1', 'L', '1'};
            else if (symbol == 'c') return {State::Q4, 'B', 'R', '0'};
            else return {State::Q3, symbol, 'L', '1'};
        case State::Q4:
            if (symbol == '1') return {State::Q5, '1', 'R', '1'};
            else return {State::Q4, symbol, 'R', '0'};
        case State::Q5:
            if (symbol == '1') return {State::Q5, '1', 'R', '1'};
            else if (symbol == '0') return {State::Q6, 'B', 'R', '1'};
            else return {State::Q5, symbol, 'R', '1'};
        case State::Q6:
            if (symbol == '1') return {State::Q7, 'B', 'S', '1'};
            else return {State::Q6, symbol, 'R', '1'};
        default:
            return {State::Q7, ' ', ' ', ' '};  // Halt state
    }
}

std::string compareNumbers(const std::string& input) {
    std::string tape = input;
    State current = State::Q0;
    size_t headPosition = 0;

    while (current != State::Q7) {
        char currentSymbol = tape[headPosition];
        auto [newState, newSymbol, moveDirection, replaceSymbol] = transition(current, currentSymbol);

        tape[headPosition] = newSymbol;
        headPosition += (moveDirection == 'R') ? 1 : (moveDirection == 'L') ? -1 : 0;
        current = newState;
    }

    return tape;
}

int main() {
    std::string input = "0111c11110";
    std::string result = compareNumbers(input);
    std::cout << result << std::endl;

    return 0;
}
