#include <format>
#include <print.hpp>
#include <iostream>


class MixedFraction
{
public:
    MixedFraction(int dividend, int divisor) 
    {
        _quotient = dividend / divisor;
        _num = dividend - (_quotient * divisor);
        _denom = divisor;
        if (_num == 0)
        {
            _denom = 0;
        }
        else { _reduce(_num, _denom); }
    };
    //getters
    int getQuotient() const { return _quotient; };
    int getNum() const { return _num; };
    int getDenom() const { return _denom; };

    //Rule of five
    MixedFraction() = delete;                            //no default constructor                         
    MixedFraction(const MixedFraction&) = delete;        //no copy
    MixedFraction& operator = (MixedFraction) = delete;  //no assignment
    MixedFraction(MixedFraction &&) = delete;            //no move    
private:
    int _num{ 0 };
    int _denom{ 0 };
    int _quotient{ 0 };
    //utilities
    int _euclid(int a, int b);
    void _reduce(int& num, int& denom);
};


//implementation
int MixedFraction::_euclid(int a, int b)
{
    if(a < b)
    {
        int temp{a};
        a = b;
        b = temp;
    }
    int rem{a - (a/b * b)};             //remainder
    if (rem == 0)                            //return condition
    {
        return b;
        printf("GCD is %d\n", b);
    }                  
    else
    {
        _euclid(b,rem); 
    }      
}

void MixedFraction::_reduce(int& num, int& denom)
{
    int divisor{_euclid(num, denom)};
    num = num / divisor;
    denom = denom / divisor;
}

//Formatter Specification
template<>
struct std::formatter<MixedFraction>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx)
    {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(const MixedFraction& mf, FormatContext& ctx)
    {
        if (mf.getNum() == 0)
            return format_to(ctx.out(), "{:d}", mf.getQuotient());
        else 
            return format_to(ctx.out(), "{0:d} {1:d}/{2:d}", mf.getQuotient(), mf.getNum()
            , mf.getDenom());
    }
};

int main()
{
    int num1{0}, num2{0};
    print("Enter a fraction: \n1. numerator: ");
    std::cin  >> num1;
    print ("\n2. Denominator: ");
    std::cin >> num2;
    MixedFraction mf{ num1, num2 };

    print("\nThe numbers expressed as a mixed fraction is: {}", mf);

    return 0;
}