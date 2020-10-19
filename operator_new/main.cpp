#include <iostream>

class A
{
public:
	A(int i1, int i2) : a1{i1}, a2{i2} { std::cout << "A ctor\n"; }
	A() { std::cout << "A zero-argument ctor\n"; }
	virtual ~A() = default;
	static void* operator new(size_t size)
	{
		std::cout << "A operator new, siz is " << size << "\n";
		return ::operator new(size);
	}
	static void operator delete(void *p)
	{
		std::cout << "A operaotr delete, p is " << p << "\n";
		::operator delete(p);
	}

	// prohibit creating array on heap
	static void* operator new[](size_t size) = delete;
	static void operator delete[](void *p) = delete;

private:
	int a1 = 0;
	int a2 = 0;
};

class B : public A
{
public:
	B(int i1, int i2, int i3) : A{i1, i2}, b1{i3} { std::cout << "B ctor\n"; }
	virtual ~B() = default;
	static void* operator new(size_t size)
	{
		std::cout << "B operator new, siz is " << size << "\n";
		return ::operator new(size);
	}
	static void operator delete(void *p)
	{
		std::cout << "B operaotr delete, p is " << p << "\n";
		::operator delete(p);
	}

private:
	int b1;
};

class C
{
public:
	C() { std::cout << "C ctor\n"; }

	// prohibit creating object on heap
	static void* operator new(size_t size) = delete;
	static void operator delete(void *p) = delete;
};

int main()
{
	A* pa = new A{8, 4};
	delete pa;
	A* pb = new B{3, 5, 9};
	delete pb;
	C c{}; // creating C on stack is allowed
	/* compile errors out with following definitions
	A* aArr = new A[7];
	delete[] aArr;
	C* pc = new C{};
	delete pc;
	*/
	return 0;
}
