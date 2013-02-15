#include <iostream>

using namespace std;


void fi(char v[])
{
    for (int i = 0; v[i] != 0; i++)
        cout << v[i];
}

void fp(char v[])
{
    for (char *p = v; *p != 0; p++)
        cout << *p;
}

int main(void)
{
    char ddd[] = "abcdefghijklmn";

    fi(ddd);
    fp(ddd);

    return 0;
}

#if 0
// g++ -O1 -S 8.cpp 로 빌드하면 다음과 같이 두 함수의 루프 부분이 동일하다
.L3:
	movb	%al, 15(%rsp)
	movl	$1, %edx
	leaq	15(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	addl	$1, %ebx
	movslq	%ebx, %rax
	movzbl	0(%rbp,%rax), %eax
	testb	%al, %al
	jne	.L3
.L1:

.L7:
	movb	%al, 15(%rsp)
	movl	$1, %edx
	leaq	15(%rsp), %rsi
	movl	$_ZSt4cout, %edi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	addq	$1, %rbx
	movzbl	(%rbx), %eax
	testb	%al, %al
	jne	.L7
.L5:                

// g++ -O2 -S 8.cpp로 빌드해도 동일한 루프가 생성된다
.L3:
	leaq	15(%rsp), %rsi
	addq	$1, %rbx
	movl	$1, %edx
	movl	$_ZSt4cout, %edi
	movb	%al, 15(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movzbl	(%rbx), %eax
	testb	%al, %al
	jne	.L3
.L1:


.L8:
	leaq	15(%rsp), %rsi
	addq	$1, %rbx
	movl	$1, %edx
	movl	$_ZSt4cout, %edi
	movb	%al, 15(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movzbl	(%rbx), %eax
	testb	%al, %al
	jne	.L8
.L6:

#endif
