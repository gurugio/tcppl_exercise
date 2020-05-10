#include <iostream>

using namespace std;


int _atoi_base(const char* src, int base = 10)
{
	int t = 0;
	int digit;

	while (*src) {
		if (base == 16) {
			if ('0' <= *src && *src <= '9')
				digit = *src - '0';
			else if ('a' <= *src && *src <= 'f')
				digit = (*src - 'a') + 10;
			else if ('A' <= *src && *src <= 'F')
				digit = (*src - 'A') + 10;
		} else {
			digit = *src - '0';
		}
		t = t*base + digit;
		src++;
	}
	return t;
}

enum class FLAG {PLUS, MINUS, CHAR_CONST};

int atoi(const char* src)
{
	int ret;
	FLAG flag = FLAG::PLUS;

	if (*src == '\\')
		flag = FLAG::CHAR_CONST;
	else if (*src == '-')
		flag = FLAG::MINUS;
	
	if (*src == '0' && *(src+1) == 0)
		ret = 0;
	else if ((*src == '0' || *src == '\\') && *(src+1) == 'x')
		ret = _atoi_base(src+2, 16);
	else if (*src == '0' || *src == '\\')
		ret = _atoi_base(src + 1, 8);
	else {
		if (flag == FLAG::MINUS)
			ret = _atoi_base(src + 1);
		else
			ret = _atoi_base(src);
	}

	if (flag == FLAG::CHAR_CONST) {
		if (ret > 128)
			ret = -(255 - ret + 1);
	}

	if (flag == FLAG::MINUS) {
		ret = -ret;
	}
	
	return ret;
}

// gkim@laptop:~/tcppl_exercise/X10$ g++ 4.cpp && ./a.out
// decimal
// 3=3
// 13=13
// -26=-26
// -363=-363
// -3846=-3846
// octal
// 0=0
// 3=3
// 11=11
// 22=22
// 243=243
// 2022=2022
// octal with \
// 3=3
// 11=11
// 22=22
// -1=-1
// hex
// 3=3
// 19=19
// 38=38
// 1022=1022
// 43981=43981
// hex with \
// 3=3
// 19=19
// 38=38
// -2=-2
// -1=-1

int main(void)
{
	cout << "decimal\n";
	cout << atoi("3") << '=' << 3 << endl;
	cout << atoi("13") << '=' << 13 << endl;
	cout << atoi("-26") << "=" << -26 <<  endl;
	cout << atoi("-363") << "=" << -363 << endl;
	cout << atoi("-3846") << "=" << -3846 << endl;

	cout << "octal\n";
	cout << atoi("0") << '=' << 0 << endl;
	cout << atoi("03") << '=' << 03 << endl;
	cout << atoi("013") << '=' << 013 << endl;
	cout << atoi("026") << '=' << 026  << endl;
	cout << atoi("0363") << '=' << 0363  << endl;
	cout << atoi("03746") << '=' << 03746 << endl;

	cout << "octal with \\" << endl;
	cout << atoi("\\3") << '=' << static_cast<int>('\3') << endl;
	cout << atoi("\\13") << '=' << static_cast<int>('\13') << endl;
	cout << atoi("\\26") << '=' << static_cast<int>('\26')  << endl;
	cout << atoi("\\377") << '=' << static_cast<int>('\377')  << endl;

	cout << "hex\n";
	cout << atoi("0x3") << '=' << 0x3 << endl;
	cout << atoi("0x13") << '=' << 0x13 << endl;
	cout << atoi("0x26") << '=' << 0x26  << endl;
	cout << atoi("0x3fe") << '=' << 0x3fe  << endl;
	cout << atoi("0xabcd") << '=' << 0xabcd << endl;

	cout << "hex with \\" << endl;
	cout << atoi("\\x3") << '=' << static_cast<int>('\x3') << endl;
	cout << atoi("\\x13") << '=' << static_cast<int>('\x13') << endl;
	cout << atoi("\\x26") << '=' << static_cast<int>('\x26')  << endl;
	cout << atoi("\\xfe") << '=' << static_cast<int>('\xfe')  << endl;
	cout << atoi("\\xff") << '=' << static_cast<int>('\xff') << endl;

	return 0;
}
