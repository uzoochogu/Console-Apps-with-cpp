#include <cstdio>               //if using header files, put before module export
#include <format>
export module MixedFraction;


export class MixedFraction
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

