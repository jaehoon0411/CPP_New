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