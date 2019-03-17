#include "learning.h"

#include <iostream>

namespace inheritance_test
{

class A1
{
	int a, b;

public:

	A1 (const A1& x)
	{
		a = x.a;
		b = x.b;
		std::cout << 1;
	}

	A1 (int a = 0, int b = 0)
	{
		this -> a = a;
		b = a;
		std::cout << 2;
	}
};

void f1 ()
{
	A1 x (1);
	A1 y;
	A1 z = A1 (2.5, 4);
	A1 s = 6;
	A1 w = z;
	x = z = w;

	// 22221
}

void test1()
{
	std::cout << "Test 1:" << std::endl;
	f1();
	std::cout << std::endl;

}

class A2
{

public:
	A2(int a = 0, int b = 1)
	{
	}
};

void f2()
{
	A2 a;
	A2 b(1);
	A2 c(1, 2);
	A2 d('1', 1);
}

class X3a
{
	int i;
	double t;

	X3a(int k)
	{
		i = k;
		t = 0;
		std::cout << 1;
	}
public:
	X3a(int k, double r = 0)
	{
		i = k;
		t = r;
		std::cout << 2;
	}
	X3a& operator= (X3a & a)
	{
		i = a.i;
		t = a.t;
		std::cout << 3;
		return * this;
	}
	X3a(const X3a & a)
	{
		i = a.i;
		t = a.t;
		std::cout << 4;
	}
};

void f3a()
{
	// X3a a;
	// X3a b(1);
	X3a c (2, 3.5);
	X3a d = c;
	X3a e (6.5, 3);
	c = d = e;

	// 24233
}

class X3b
{
	int i;
	double t;
	X3b()
	{
		i = 0;
		t = 1.0;
		std::cout << 1;
	}
public:
	X3b(int k = 0, double r = 1.5)
	{
		i = k;
		t = r;
		std::cout << 2;
	}
	X3b(const X3b & a)
	{
		i = a.i;
		t = a.t;
		std::cout << 3;
	}
};

void f3b()
{
	// X3b a;
	X3b b(1);
	X3b c (1.5, 2);
	X3b d = b;
	X3b e = 3;
	b = c = e;

	// 2232
}

void test3()
{
	f3a();
	std::cout << std::endl;
	f3b();
	std::cout << std::endl;
}

class A4 // 100 300
{
	int x;
public:
	A4(int a) : x(a) {}
	int operator *= (int a) { return x *= a; }
	int get() const { return x; }
};

void f4()
{
	A4 a1 (5), a2 = 3;
	a1 *= 10;
	a2 *=
	a1 *= 2;
	std::cout << a1.get() << a2.get() << std::endl;
}

void test4()
{
	f4();
}

class B5 // 10 20 30
{
	int x;
public:
	B5(): x(10) {}
	B5(const B5& b) { x = b.x + 10; }
	int get() const { return x; }
};

void test5()
{
	B5 b1, b2 = b1, b3 (b2);
	std::cout << b1.get() << b2.get() << b3.get() << std::endl;
}

class C6 // 14 10 48
{
	int x;
public:
	C6(int a): x(a*2) {}
	int get() const { return x; }
	friend int operator + (const C6& op1, const C6& op2)
	{
		return op1.x + op2.x;
	}
};

void test6()
{
	C6 c1 (7), c2 = 5, c3 (c1 + c2);
	std::cout << c1.get() << c2.get() << c3.get () << std::endl;
}

class A7 // 1 contructor, 15 60 7
{
	int x;
public:
	A7(int a = 7): x(a) {}
	int operator *= (int a) {return x *= a; }
	int get() const { return x; }
};

void test7()
{
	A7 a1(5), a2 = 4, a3;
	a2 *= a1 *= 3;
	std::cout << a1.get( ) << ' ' << a2.get() << ' ' << a3.get() << std::endl;
}

class I10
{
	int i;
public:
	I10() : i(9) { std::cout << "sun" << std::endl; }
	I10(int a) : i(a) { std::cout << "venus " << i << std::endl; }
	I10(const I10 & other) : i(other.i) { std::cout << "earth " << i << std::endl; }
	~I10() { std::cout << "moon" << std::endl; }
	int Get() { return i; }
	void operator+= (const I10 & op) { i+=op.i; }
};

void f10(I10 & x, I10 y)
{
	y += 1000;
	x += y;
}

void test10()
{
	I10 i1; //9
	I10 i2(20); //9, 20
	i2 += 400; // 9, 420
	f10(i1, i2); // 1429
	std::cout << i1.Get() << i2.Get() << std::endl;
	// sun, venus, venus, moon, earth, venus, moon, moon
	// 1429 420
	// moon, moon
}
}
