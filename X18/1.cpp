#include <iostream>

using namespace std;

class X {
public:
	X(int n): data{n} {
		cout << "this: " << this;
		cout << " constructor with " << n << endl;
	}
		
	X() {
		cout << "this: " << this;
		cout << " constructor without arg\n";
	}

	X(const X& xx) {
		cout << "this: " << this;
		cout << " copy-constructor with " << &xx << endl;
		cout << "data:" << data << "->" << xx.data << endl;
		data = xx.data;
	}

	X(X&& rhs) {
		cout << "this: " << this << "move-consturctor with " << &rhs << endl;
		cout << "data:" << data << "->" << rhs.data << endl;
		data = rhs.data;
		rhs.data = -1;
	}

	X& operator=(const X& xx) {
		cout << "copy-assign: target=" << this << " src=" << &xx << endl;
		cout << "data:" << data << "->" << xx.data << endl;
		data = xx.data;
		return *this;
	}

	X& operator=(X&& rhs) {
		cout << "move-assign: target=" << this << " src=" << &rhs << endl;
		cout << "data:" << data << "->" << rhs.data << endl;
		data = rhs.data;
		return *this;
	}
	
	~X() {
		cout << "this: " << this << " destructor: data=" << data << endl;
	}

private:
	int data;
};

X try_move(X& xx)
{
	X ret = xx;
	return ret;
}

void try_arg(X xx)
{
	cout << "  start try-arg body\n";
	cout << "  end try-arg body\n";
}

int main(void)
{
	X x_var; // data is not initialized
	X x_var2 = X{22}; // neither copy nor move
	X* x_var3 = new X{33};

	x_var = x_var2; // copy-assign

	cout << "====start try-move\n";
	x_var = try_move(*x_var3); // move and rvalue is destructed immediately
	cout << "====end try-move\n";
	
	cout << "====start try-arg\n";
	try_arg(x_var); // copy-constructor and argument is destructed immediately
	cout << "====end try-arg\n";

	cout << "====end of main\n";
	delete x_var3;
}
