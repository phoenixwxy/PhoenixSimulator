#include <iostream>

#include <stdio.h>
#include <memory>


#include "Test.h"

#include "std_utility.h"

int main()
{
    std::cout << "--------------------------------------------" << std::endl << "\t\tTest CPP Begin" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    auto test = std::unique_ptr<Test>();

    // TODO Error this function
//    test->TestLoadRawAndPrint();
//    auto pTest = new Test();
//    pTest->TestVoid();
//    auto StdUtility = new std_utility();
//
//    StdUtility->forward();
//
//    delete StdUtility;


    std::cout << "--------------------------------------------" << std::endl << "\t\tTest CPP End" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    return 0;
}


//#include <iostream>
//#include <type_traits>
//#include <typeinfo>
//#include <memory>
////using namespace std;
//
//struct A
//{
//    A(int&& n)
//    {
//        std::cout << "rvalue overload, n=" << n << std::endl;
//    }
//    A(int& n)
//    {
//        std::cout << "lvalue overload, n=" << n << std::endl;
//    }
//};
//
//class B
//{
//public:
//    template<class T1, class T2, class T3>
//    B(T1 && t1, T2 && t2, T3 && t3) :
//            a1_(std::forward<T1>(t1)),
//            a2_(std::forward<T2>(t2)),
//            a3_(std::forward<T3>(t3))
//    {
//
//    }
//private:
//    A a1_, a2_, a3_;
//};
//
//template <class T, class U>
//std::unique_ptr<T> make_unique1(U&& u)
//{
//    return std::unique_ptr<T>(new T(std::forward<U>(u)));
////    return std::unique_ptr<T>(new T(std::move(u)));
//}
//
//template <class T, class... U>
//std::unique_ptr<T> make_unique(U&&... u)
//{
//    return std::unique_ptr<T>(new T(std::forward<U>(u)...));
////    return std::unique_ptr<T>(new T(std::move(u)...));
//}
//
//int main()
//{
//    auto p1 = make_unique1<A>(2);
//
//    int i = 10;
//    auto p2 = make_unique1<A>(i);
//
//    int j = 100;
//    auto p3 = make_unique<B>(i, 2, j);
//    return 0;
//}