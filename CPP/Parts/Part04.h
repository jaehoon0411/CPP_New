#pragma once

namespace Part04_Inheritance
{
	class Base
	{
	public:
		Base(int num, float fltNum);
		~Base();

		void PrintInfo() const;

	// 접근제어중 상속관계에서는 접근을 허용함, 나로인해 파생된 애한테는 허용
	protected:
		int num = 0;
		float fltNum = 0.0f;
	};

	// 싱속 접근제어 - 
	// public - 그대로 가지고옴
	// protecred - 가지고 올때 public이 protected로 바뀜
	// private - public과 protected가 다 
	class Derived : public Base
	{
	public:
		Derived();
		Derived(int num, float fltNum, const char* string);
		~Derived();

		void PrintInfo() const;

	private:
		char string[100] = "";
	};
}


namespace Part04_Polymorphism
{
	class Base
	{
	public:
		Base() { cout << "Base() 생성자 실행 완료!\n"; }
		virtual ~Base() { cout << "~Base() 소멸자 실행 완료!\n"; }

		virtual void ShowInfo();
	};

	class Derived : public Base
	{
	public:
		Derived() { cout << "Derived() 생성자 실행 완료!\n"; }
		~Derived() override { cout << "~Derived() 소멸자 실행 완료!\n"; }

		void ShowInfo() override;
	protected:
		virtual void DoShowInfo() = 0;
		// 순수 가상함수 - 가상함수테이블에 올라가는 가상함수는 맞으나 정의가 없다.
			// 무엇을 실행해야 하는지 알수가 없다.
			// 순수 가상함수를 한개라도 포함하는 클래스를 추상 클래스라고 부른다.
			// 추상 클래스는 말 그대로 추상적인 클래스라는 것이라서 그 클래스로 객체를 생성할 수 없다.
			// 상속받는 클래스의 기본적인 틀을 만들어 주고 상속받은 클래스에서 구현을 맡길때
			// 인터페이스
				// 
	};

	class SubDerived : public Derived
	{
	public:
		SubDerived() { cout << "SubDerived() 생성자 실행 완료!\n"; }
		~SubDerived() override { cout << "~SubDerived() 소멸자 실행 완료!\n"; }

	private:
		int val = 0;

	};
}

class Part04
{
public:
	Part04();

private:

	void Inheritance();
	void Polymorphism();
};

// 함수 호출은 보통 정적 다이닝이라고 한다