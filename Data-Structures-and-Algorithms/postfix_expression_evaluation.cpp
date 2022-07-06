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

bool isHigherPrecedence(char opr1, char opr2);

std::string postfixEvaluator(std::string expr);

int main()
{
    std::cout << "Evaluation of PostFix Expressions:\n" << "\n"; 
    std::cout << "2*3+5*4-9:     " << postfixEvaluator("2*3+5*4-9") << "\n";       //17
    std::cout << "2*3+5:         " << postfixEvaluator("2*3+5") << "\n";           //11
    std::cout << "((5+3)*4-5)*6: " << postfixEvaluator("2*3+5*4-9") << "\n";       //162

    return 0;
}