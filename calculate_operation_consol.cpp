//Created by Kilian

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // für std::stod
#include <cmath>

enum struct operation {
    plus,
    minus,
    mul,
    div,
    pow,
    invalid_operation,
};


operation string_to_op(const std::string& s) {
    if (s == "+") return operation::plus;
    if (s == "-") return operation::minus;
    if (s == "x") return operation::mul;
    if (s == "/") return operation::div;
    if (s == "^") return operation::pow;
    return operation::invalid_operation;
}


double calculate(double operand1, operation op, double operand2) {
    switch(op) {
        case operation::plus: return (operand1 + operand2);
        case operation::minus: return (operand1 - operand2);
        case operation::mul: return (operand1 * operand2);
        case operation::div: return (operand1 / operand2);
        case operation::pow: return std::pow(operand1, operand2);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: <operand1> <+|-|x|/|^> <operand2>\n";
        return 1;
    }

    double operand1 = std::stod(argv[1]);
    std::string op_str = argv[2];
    double operand2 = std::stod(argv[3]);

    if(operand2 == 0)
        std::cerr << "Fehler: Nicht durhc 0 Teilbar!" << std::endl;

    operation op = string_to_op(op_str);

    if (op == operation::invalid_operation) {
        std::cout << "Invalid operator: " << op_str << std::endl;
        return 1;
    }

    double result = calculate(operand1, op, operand2);
    std::cout << result << std::endl;

    return 0;
}
