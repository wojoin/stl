#include <stdio.h>

namespace mock {

template <class Arg, class Result>
class pointer_to_unary_function
{
protected:
    Result (*ptr)(Arg); // 一个函数指针
public:
    pointer_to_unary_function() {}
    explicit pointer_to_unary_function(Result (*x)(Arg)) : ptr(x)
    {
        printf("ctor pointer_to_unary_function\r\n");
    }

    //通过函数指针执行函数,重载operator()
    Result operator()(Arg x)
    {
        printf("operator()\r\n");
        return ptr(x);
    }
};

template<class Arg, class Result>
inline pointer_to_unary_function<Arg, Result> ptr_fun(Result (*x)(Arg))
{
    return pointer_to_unary_function<Arg, Result>(x); // 类似于显示地调用构造函数        
}

};
