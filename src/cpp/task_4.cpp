/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <tuple>

enum class State {
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12, Q13, Q14
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
            if (symbol == '0') return {State::Q3, '0', 'L', '1'};
            else return {State::Q2, symbol, 'R', '1'};
        case State::Q3:
            if (symbol == '0') return {State::Q3, '0', 'L', '1'};
            else if (symbol == 'c') return {State::Q4, 'B', 'R', '1'};
            else return {State::Q3, symbol, 'L', '1'};
        case State::Q4:
            if (symbol == 'X') return {State::Q5, 'X', 'R', '0'};
            else if (symbol == 'c') return {State::Q12, 'B', 'R', '1'};
            else return {State::Q4, symbol, 'R', '1'};
        case State::Q5:
            if (symbol == '0') return {State::Q5, '0', 'R', '0'};
            else if (symbol == 'C') return {State::Q6, 'C', 'L', '0'};
            else return {State::Q5, symbol, 'R', '0'};
        case State::Q6:
            if (symbol == 'X') return {State::Q7, 'X', 'L', '0'};
            else if (symbol == 'C') return {State::Q8, 'C', 'R', '0'};
            else return {State::Q6, symbol, 'L', '0'};
        case State::Q7:
            if (symbol == 'B') return {State::Q12, 'B', 'R', '1'};
            else if (symbol == 'Y') return {State::Q7, 'Y', 'L', '0'};
            else if (symbol == 'C') return {State::Q6, 'C', 'R', '0'};
            else return {State::Q7, symbol, 'L', '0'};
        case State::Q8:
            if (symbol == 'C') return {State::Q8, 'C', 'R', '0'};
            else if (symbol == 'Y') return {State::Q9, 'Y', 'R', '0'};
            else return {State::Q8, symbol, 'R', '0'};
        case State::Q9:
            if (symbol == 'B') return {State::Q12, 'B', 'R', '1'};
            else if (symbol == 'Y') return {State::Q9, 'Y', 'R', '0'};
            else if (symbol == 'C') return {State::Q10, 'C', 'L', '0'};
            else return {State::Q9, symbol, 'R', '0'};
        case State::Q10:
            if (symbol == 'X') return {State::Q11, 'X', 'L', '0'};
            else return {State::Q10, symbol, 'L', '0'};
        case State::Q11:
            if (symbol == 'C') return {State::Q10, 'C', 'L', '0'};
            else if (symbol == 'B') return {State::Q12, 'B', 'R', '1'};
            else if (symbol == '0') return {State::Q13, '0', 'L', '0'};
            else return {State::Q11, symbol, 'L', '0'};
        case State::Q12:
            return {State::Q12, ' ', ' ', ' '};  // Halt state
        case State::Q13:
            if (symbol == 'C') return {State::Q13, 'C', 'L', '0'};
            else if (symbol == 'X') return {State::Q14, 'X', 'L', '0'};
            else return {State::Q13, symbol, 'L', '0'};
        case State::Q14:
            if (symbol == '0') return {State::Q14, '0', 'L', '0'};
            else if (symbol == 'B') return {State::Q12, 'B', 'R', '1'};
            else if (symbol == 'C') return {State::Q13, 'C', 'L', '0'};
            else return {State::Q14, symbol, 'L', '0'};
        default:
            return {State::Q12, ' ', ' ', ' '};  // Halt state
    }
}

std::string multiplyNumbers(const std::string& input) {
    std::string tape = input;
    State current = State::Q0;
    size_t headPosition = 0;

    while (current != State::Q12) {
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
    std::string result = multiplyNumbers(input);
    std::cout << result << std::endl;

    return 0;
}
