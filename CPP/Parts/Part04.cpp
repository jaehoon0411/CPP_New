#include "pch.h"
#include "Part04.h"

Part04::Part04()
{
	//Inheritance();
	Polymorphism();
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
	SAFE_DELETE(baseDerived);
	cout << '\n';
}

// virtual - 가상 함수
	// Base의 ShowInfo를 가상함수로 선언하고 Derived에서 그 가상 함수를 override라고 표현한다
	// 이게 어떻게 가능하냐?
		// 동적 다형성
			// 함수 바인딩
				// 컴파일러가 보통은 함수호출에 무엇을 묶어주는 것, 보통은 정적 바인딩이다.
				// 마치 함수 호출이 동적 바인딩이 된것처럼 보이기에 동적 바인딩이라고 표현함.
	// override가 무엇이냐?
		// 재정의, 즉 함수를 다시 정의한다
	// 구현 원리 - 가상함수 포인터, 가상함수 테이블
// 업케스팅
	// 케스팅 -- 형변환
	// 파생 클래스 포인터를 기반 클래스 포인터로 형변환 하는것을 업케스팅
	// 업이란 것은 상속 관계에서의 업이란 것
	// new Derived = Derived*이기에 Base로 받을 때 실행되는 것을 업케스팅이라고 한다
		// 묵시적 형변환 - 형변환을 명시하지 않았지만 컴파일러가 형변환을 할때
		// 값이 소실될수 있음
	// Derived는 Base를 포함하고 있기에 Base*로 하여도 너무나도 당연하게 가능한 형변환이다.

	// baseDerived는 Derived의 객체이기에 사람의 입장에서는 Derived의 PrintInfo이기를 바람
		// 상속이 다양하게 많은 종류로 일어날수 있다.
			// 종류별로 다 따로 하기 힘듬

	// 
void Part04::Polymorphism()
{
	using namespace Part04_Polymorphism;

	Base* base1 = new Base();
	cout << '\n';
	Base* base2 = new Derived();
	cout << '\n';

	base1->ShowInfo();
	base2->ShowInfo();
	cout << '\n';
	
	SAFE_DELETE(base2);
	cout << '\n';
	SAFE_DELETE(base1);
	cout << '\n';
}

namespace Part04_Inheritance
{
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

// Base*에 Derived클래스 객체의 주소를 담았을때 baseDerived.PrintInfo() -> Base::PrintInfo()가 됨
// 만일 애매했다면 컴파일러가 모호하다면서 에러를 띄웠을 것이나 실행이 되었다.
// 포인터 멤버접근 연산자는 간접 참조와 같은것이니 baseDrived는 Base형이니 Base만 나온다.

namespace Part04_Polymorphism
{
	void Base::ShowInfo()
	{
		cout << "Base::ShowInfo() 실행 완료!\n";
	}

	void Derived::ShowInfo()
	{
		cout << "Derived::ShowInfo() 실행 완료!\n";
	}
}