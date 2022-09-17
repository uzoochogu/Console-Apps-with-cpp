#include <iostream>
#include <print.hpp>
import MixedFraction;


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
        else if (mf.getQuotient() == 0)
            return format_to(ctx.out(), "{0:d}/{1:d}", mf.getNum(), mf.getDenom());
        else
            return format_to(ctx.out(), "{0:d} {1:d}/{2:d}", mf.getQuotient(), mf.getNum(), mf.getDenom());
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
