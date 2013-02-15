#include <iostream>


using namespace std;

// 9번 루프돌것을 1번만 루프를 돌고 한 루프안에서 8번씩 복사를 한다.
void send(int *to, int *from, int count)
{
    int n = (count + 7)/8;
    switch (count % 8) {
        case 0: do { *to++ = *from++;
            case 7: *to++ = *from++;
            case 6: *to++ = *from++;
            case 5:  *to++ = *from++;
            case 4:  *to++ = *from++;
            case 3:  *to++ = *from++;
            case 2:  *to++ = *from++;
            case 1:  *to++ = *from++;
        } while(--n > 0);
    }
}


int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[100];

    send(b, a, 9);

    cout << b[0] << b [8] << endl;
}

