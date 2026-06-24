#include "pch.h"
#include "Part04.h"

Part04::Part04()
{
	Inheritance();
}

// 상속 - 기반을 포함하여 +@로 넣는다 
void Part04::Inheritance()
{
	using namespace Part04_Inheritance;

	Base base(10, 3.14f);
	cout << '\n';
	base.PrintInfo();
	cout << '\n';

	Derived derived(3, 0.1f, "Hello, World!");
	cout << '\n';
	derived.PrintInfo();
	cout << '\n';

	Base* baseDerived = new Derived(20, 6.28f, "Hello!");
	cout << '\n';
	baseDerived->PrintInfo();
	cout << '\n';

}

// namespace - 
namespace Part04_Inheritance
{
	// 
	Base::Base(int num, float fltNum)
		: num(num), fltNum(fltNum)
	{
		cout << "Base(int, float) 생성자 실행 완료!\n";
	}

	Base::~Base()
	{
		cout << "~Base() 소멸자 실행 완료!\n";
	}

	void Base::PrintInfo() const
	{
		cout << "===== 기반 객체 정보 =====\n";
		cout << "Int : " << num << '\n';
		cout << "Float : " << fltNum << '\n';
	}

	Derived::Derived()
		: Derived(0, 0.0f, "")
	{
		cout << "Derived() 생성자 실행 완료!\n";
	}

	Derived::Derived(int num, float fltNum, const char* string)
		: Base(num, fltNum)
	{
		strcpy(this->string, string);
		cout << "Derived(int, float, const char*) 생성자 실행 완료!\n";
	}

	Derived::~Derived()
	{
		cout << "~Derived() 소멸자 실행 완료!\n";
	}

	void Derived::PrintInfo() const
	{
		Base::PrintInfo();

		cout << "===== 파생 객체 정보 =====\n";
		cout << "String : " << string << '\n';
	}
}

// 클래스 포인터가 파생 클래스를 담을수 있는지
	// Base* ptr = &derided가 가능한지
		// 주소는 담기지만 derided 객체가 생성을 하여 가질수 있느냐
			// 그렇다면 Base* ptr = new Derived가 가능한가? 가능하다.
				// 왜? - printInfo를 두개를 만듬 - 기반의 프린트인포와 파생의 두가지

// Base* ptr에 Derived의 객체를 생성하여 주소를 받아냄
// Derived는 Base의 상속을 받았기에 Base생성자를 호출하고 그 뒤에 Derived생성자를 호출
// 이때의 값은 20, 6.28f, "Hello!";
// ptr에 멤버접근 연산자로 접근하였을때 생성된 Derived의 객체의 주소를 가지고 있으나 ptr 자체는 Base이기에 Derived의 기반인 Base의 PrintInfo만을 호출함