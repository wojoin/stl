#include <iostream>
#include "stl_function.h"

using namespace std;

int increment(int x)
{
    cout << __FUNCTION__ << ":increment one" << endl;
    return ++x;
}

void print(int x)
{
    cout << __FUNCTION__ << ":x = " << x << endl;
}

void pr()
{
    cout << "pr\r\n" << endl;
}

int main(int argc, char* argv[])
{
    mock::pointer_to_unary_function<int,int> pinc(increment); // template形式
    cout << pinc(42) << endl;
    
    cout << "---------------------------------------"<< endl;
    mock::pointer_to_unary_function<int, void> pprint = mock::ptr_fun(print); //adapter形式
    pprint(42); 
    
    // mock::ptr_func(print);这只是将print函数绑定，并没有调用print调用，相当于延迟了print的调用,
    // 这就给回调函数创造了合适的调用就会，其实回调函数的本质就是函数指针的延迟调用
    mock::ptr_fun(print)(12);
    return 0;

}
