/*
This program evaluates a given Postfix expression

Limitations:
1. Only single digits are evaluated
2. + - * / are the only supported operators
*/
#include <iostream>
#include <string>
#include <stack>

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

    return op1 > op2? true: false;    
}

bool isOperator(char s)
{
    if( s == '*' || s == '/'  || s == '+' || s == '-')
        return true;
    else
        return false;
}

bool isOperand(char s)
{
    if( s > 47 && s < 58)
        return true;
    else
        return false;
}

double postfixEvaluator(std::string expr)
{
    std::stack<char> s;
    double buf, result{0};
    int oprnd1, oprnd2;
    std::string postfix;

    for(unsigned int i = 0; i < expr.size(); i++ )
    {
        if(isOperand(expr[i]))
            postfix.push_back(expr[i]);
        
        else if(isOperator(expr[i]))
        {
            while(!s.empty() && s.top() != '(' && isHigherPrecedence(s.top(), expr[i]) )
            {
                postfix.push_back(s.top());
            }
        }

        else if(expr[i] == '(')
            s.push(expr[i]);
        
        else if(expr[i] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
        }

        while(!s.empty())
        {
            postfix.push_back(s.top());
            s.pop();
        }       

    } 
    for(auto i : postfix)
        std::cout << i << "\n";

    std::cout << postfix.size() << "\n";

    //std::stack<char> g{s};

    /*
    while(!g.empty())
    {
        std::cout << g.top() << "\n";
        g.pop();
    }
     */

    /* oprnd1 = std::stod(std::string{postfix[0]});
    
    for(unsigned int i = 1; i < postfix.size(); i++)
    {
        int checker{postfix.size()- 1};
        char operatorName;
        if(isOperand(postfix[i]))
        {
            while(isOperator(postfix[checker]))
            {
                operatorName = postfix[checker];
                checker--;
            }
            oprnd2 = std::stod(std::string{postfix[i]});

            oprnd1 = opr(operatorName, oprnd1, oprnd2);

            postfix.erase(postfix.begin()+ checker);
        }
    }

    result = oprnd1; */

    return result;
}


int main()
{
    std::cout << "Evaluation of PostFix Expressions:\n" << "\n"; 
    std::cout << "2*3+5*4-9:     " << postfixEvaluator("2*3+5*4-9") << "\n";       //17
    //std::cout << "2*3+5:         " << postfixEvaluator("2*3+5") << "\n";           //11
    //std::cout << "((5+3)*4-5)*6: " << postfixEvaluator("2*3+5*4-9") << "\n";       //162

    return 0;
}