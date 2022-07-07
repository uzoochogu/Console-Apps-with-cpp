/*
This program evaluates a given Postfix expression
*/
#include <iostream>
#include <string>

double opr(char opr, int op1, int op2 )
{
    double result{0};
    switch(opr)
    {
        case '*':
        result = op1 * op2;
        break;

        case '/':
        result = op1 / op2;
        break;

        case '+':
        result = op1 + op2;
        break;

        case '-':
        result = op1 - op2;
        break;

        default:
        std::cout << "Invalid Operator";
        break;
    }
    return result;
}
enum OperatorsPrecedence
{
    multiply = 13,
    divide = 13,
    plus = 12,
    subtract = 12
};

bool isHigherPrecedence(char opr1, char opr2)
{
    OperatorsPrecedence op1, op2;
    switch(opr1)
    {
        case '*':
        op1 = multiply;
        break;

        case '/':
        op1 = divide;
        break;

        case '+':
        op1 = plus;
        break;

        case '-':
        op1 = subtract;
        break;
    }

    switch(opr2)
    {
        case '*':
        op2 = multiply;
        break;

        case '/':
        op2 = divide;
        break;

        case '+':
        op2 = plus;
        break;

        case '-':
        op2 = subtract;
        break;
    }

    op1 > op2? true: false;    
}

std::string postfixEvaluator(std::string expr);

int main()
{
    std::cout << "Evaluation of PostFix Expressions:\n" << "\n"; 
    std::cout << "2*3+5*4-9:     " << postfixEvaluator("2*3+5*4-9") << "\n";       //17
    std::cout << "2*3+5:         " << postfixEvaluator("2*3+5") << "\n";           //11
    std::cout << "((5+3)*4-5)*6: " << postfixEvaluator("2*3+5*4-9") << "\n";       //162

    return 0;
}