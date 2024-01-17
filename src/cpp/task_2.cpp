/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <string>

enum class State {
    Q0, Q1, Q2, Q3, Q4
};

std::tuple<State, char, char, char> transition(State current, char symbol) {
    switch (current) {
        case State::Q0:
            if (symbol == '1') return {State::Q1, 'X', 'R', '0'};
            else return {State::Q0, symbol, 'R', '0'};
        case State::Q1:
            if (symbol == '0') return {State::Q2, 'B', 'L', '0'};
            else return {State::Q1, symbol, 'R', '0'};
        case State::Q2:
            if (symbol == '0') return {State::Q3, 'B', 'R', '0'};
            else return {State::Q2, symbol, 'L', '0'};
        case State::Q3:
            if (symbol == '1') return {State::Q3, '1', 'R', '0'};
            else return {State::Q3, symbol, 'R', '0'};
        default:
            return {State::Q4, ' ', ' ', ' '};  // Halt state
    }
}

std::string unaryAddition(const std::string& input) {
    std::string tape = input;
    State current = State::Q0;
    size_t headPosition = 0;

    while (current != State::Q4) {
        char currentSymbol = tape[headPosition];
        auto [newState, newSymbol, moveDirection, replaceSymbol] = transition(current, currentSymbol);

        tape[headPosition] = newSymbol;
        headPosition += (moveDirection == 'R') ? 1 : (moveDirection == 'L') ? -1 : 0;
        current = newState;
    }

    return tape;
}


