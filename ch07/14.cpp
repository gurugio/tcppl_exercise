#include<iostream>


using namespace std;


#define PI = 3.141;
#define MAX(a,b) a>b!a:b
#define fac(a) (a)*fac((a)-1)

int main(void)
{
    cout << PI << endl;

    cout << MAX(31,2) << endl;

    cout << fac(5) << endl;
    
}


g++ -E 14.cpp로 프로프로세싱한 결과

=가 문제됨
    cout << = 3.141; << endl;

연산자 우선순위문제인가?
    cout << 31>2!31:2 << endl;

fac가 계속 호출되는게 아니라 fac라는 글자만 남음
    cout << (5)*fac((5)-1) << endl;
